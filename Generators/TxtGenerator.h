#ifndef TXTGENERATOR_H
#define TXTGENERATOR_H

#include "../interfaces/IReportGenerator.h"
#include "../globals/Globals.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

class TxtGenerator : IReportGenerator<std::unordered_map<std::string, WordEntry>>{
public:

    ~TxtGenerator() = default;

    void generateReport(const std::unordered_map<std::string, WordEntry>* dictionary_map) const override{
        if(!dictionary_map || dictionary_map->empty()) {
            std::cout << "No products available. You have to scan the directory otherwise it is empty." << std::endl;
            return;
        }
        try {
            std::ofstream file{text_output_path};
            if(!file.is_open()) {
                throw std::runtime_error("TxtGenerator::generateReport: File cannot be opened.");
            }

            for(const auto& [word, entry] : *dictionary_map) {
                file << "Word: " << word;
                file << ". Frequency: " << entry.get_frequency();
                file << ". Sources: [ ";

                const auto& sources = entry.get_accurence();
                for (const auto& src : sources) {
                    file << src << ", ";
                }

                file << "]\n";
            }
            std::cout << "Report saving is done." << "\n";
        }catch(const std::exception &e) {
            std::cerr << "TxtGenerator::generateReport error: " << e.what() << std::endl;
        }
    };

};



#endif //TXTGENERATOR_H
