#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H


#include "../managers/DictionaryManager.h"
#include "../interfaces/IFileProcessor.h"
#include "../text/Sanitizer.h"

#include <unordered_map>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

class TextProcessor : public IFileProcessor<DictionaryManager>{
public:
    void work_with_file(const std::filesystem::path& file_path, DictionaryManager& manager) {
        try {
            std::ifstream file(file_path);
            if(!file.is_open()) {
                throw std::runtime_error("File could not be opened.");
            }
            std::unordered_map<std::string, WordEntry> local_dictionary;
            Sanitizer sanitizer;
            std::string line;

            while(std::getline(file, line)) {
                std::stringstream ss(line);
                std::string rawWord;

                while (ss >> rawWord) {
                    std::string clean = sanitizer.sanitize(rawWord);
                    if (!clean.empty()) {
                        if(local_dictionary[clean].get_frequency() == 0) {
                            local_dictionary[clean] = WordEntry(clean);
                            local_dictionary[clean].add_occurrence(file_path.filename());
                        }else {
                            local_dictionary[clean].add_frequency();
                        }
                    }
                }
            }
            manager.merge(local_dictionary, file_path);
        }catch (const std::exception& e) {
            std::cerr << "TextProcessor::work_with_file: " << e.what() << std::endl;
        }
    };
    ~TextProcessor() = default;
};


#endif //TEXTPROCESSOR_H
