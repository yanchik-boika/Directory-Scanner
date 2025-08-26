#include "CsvFileCollector.h"
#include "../globals/includes.h"


void CsvFileCollector::push_batch_to_global(std::vector<std::filesystem::path>& local_paths) const {
    std::unique_lock<std::mutex> lock(csv_global_paths_mutex);
    for(auto& path : local_paths) {
        csv_global_paths.push_back(std::move(path));
    }
    local_paths.clear();
    lock.unlock();

}


void CsvFileCollector::collectFiles(const std::filesystem::path& dir) const {

    try {
        if(!is_directory(dir)) {
            throw std::runtime_error("CsvFileCollector::collectFiles: No such directory");
        }
        scanning_done = false;
        std::vector<std::filesystem::path> local_files_paths;
        for(const auto& entry : std::filesystem::directory_iterator(dir)) {
            if(entry.path().extension() == ".csv") {
                local_files_paths.push_back(entry.path());
            }
            if(local_files_paths.size() >= 50) {
                this->push_batch_to_global(local_files_paths);
                csv_global_condition.notify_all();
            }
        }
        if(!local_files_paths.empty()) {
            this->push_batch_to_global(local_files_paths);
            csv_global_condition.notify_all();
        }
        scanning_done = true;
        csv_global_condition.notify_all();
    }catch(std::exception& e) {
        std::cout << "CsvFileCollector::collectFiles: exception thrown." << e.what() << std::endl;
        scanning_done = true;
        csv_global_condition.notify_all();

    }
}
