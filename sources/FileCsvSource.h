#ifndef FILECSVSOURCE_H
#define FILECSVSOURCE_H

#include "../managers/ProductManager.h"
#include "../csv/CsvProcessor.h"
#include "../interfaces/ITextSource.h"
#include <iostream>
#include <vector>
#include <filesystem>

class FileCsvSource : public ITextSource<ProductManager>{
public:
    void streamToProcessor(ProductManager& manager) override {
        while(true) {
            std::filesystem::path file_path;
            std::unique_lock<std::mutex> lock(csv_global_paths_mutex);
            csv_global_condition.wait(lock, []{return !csv_global_paths.empty() || scanning_done;});

            if(csv_global_paths.empty() && scanning_done) {
                return;
            }

            file_path = std::move(csv_global_paths.back());
            csv_global_paths.pop_back();
            lock.unlock();
            try {
                CsvProcessor csv_processor;
                csv_processor.work_with_file(file_path, manager);
            }catch (const std::exception& e) {
                std::cerr << "FileCsvSource::streamToProcessor() exception: " << e.what() << std::endl;
            }
        }
    };
};



#endif //FILECSVSOURCE_H
