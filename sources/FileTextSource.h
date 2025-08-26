#ifndef FILETEXTSOURCE_H
#define FILETEXTSOURCE_H


#include "../managers/DictionaryManager.h"
#include "../text/TextProcessor.h"
#include "../interfaces/ITextSource.h"
#include <iostream>
#include <vector>
#include <filesystem>

class FileTextSource : public ITextSource<DictionaryManager>{
public:
    void streamToProcessor(DictionaryManager& manager) override {
        while(true) {
            std::filesystem::path file_path;
            std::unique_lock<std::mutex> lock(txt_global_paths_mutex);
            txt_global_condition.wait(lock, []{return !txt_global_paths.empty() || scanning_done;});
            if(txt_global_paths.empty() && scanning_done) {
                return;
            }

            file_path = std::move(txt_global_paths.back());
            txt_global_paths.pop_back();
            lock.unlock();
            try {
                TextProcessor text_processor;
                text_processor.work_with_file(file_path, manager);
            }catch (const std::exception& e) {
                std::cerr << "FileTextSource::streamToProcessor: exception caught: " << e.what() << std::endl;
            }
        }
    };
};



#endif //FILETEXTSOURCE_H
