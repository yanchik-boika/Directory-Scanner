#include "TxtFileCollector.h"
#include "../globals/includes.h"

void TxtFileCollector::push_batch_to_global(std::vector<std::filesystem::path>& local_paths) const {
    std::unique_lock<std::mutex> lock(txt_global_paths_mutex);
    for(auto& path : local_paths) {
        txt_global_paths.push_back(std::move(path));
    }
    local_paths.clear();
}

void TxtFileCollector::collectFiles(const std::filesystem::path& dir) const {

    try {
        if(!is_directory(dir)) {
            throw std::runtime_error("TxtFileCollector: directory is not exists. " + dir.string());
        }
        scanning_done = true;
        std::vector<std::filesystem::path> local_files;
        for(const auto& entry : std::filesystem::directory_iterator(dir)) {
            if(entry.path().extension() == ".txt") {
                local_files.push_back(entry.path());
            }
            if(local_files.size() >= 40) {
                this->push_batch_to_global(local_files);
                txt_global_condition.notify_all();
            }
        }
        if(!local_files.empty()) {
            this->push_batch_to_global(local_files);
            txt_global_condition.notify_all();
        }
        scanning_done = true;
        txt_global_condition.notify_all();
    }catch(const std::exception& e) {
        std::cerr << "TxtFileCollector::collectFiles: " << e.what() << std::endl;
    }

}
