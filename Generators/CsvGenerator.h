#ifndef CSVGENERATOR_H
#define CSVGENERATOR_H

#include "../interfaces/IReportGenerator.h"
#include "../globals/Globals.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

class CsvGenerator : IReportGenerator<std::unordered_map<std::string, std::unique_ptr<Product>>>{
public:
    ~CsvGenerator() = default;

    void generateReport(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) const override {
        if(!product_map || product_map->empty()) {
            std::cout << "No products available. You have to scan the directory otherwise it is empty." << std::endl;
            return;
        }

        try {
            std::ofstream file{csv_output_path};
            if(!file.is_open()) {
                throw std::runtime_error("CsvGenerator::generateReport(): Could not open output file.");
            }

            for(const auto& [name, product_ptr] : *product_map) {
                file << "ID: " << product_ptr->getId()
                << ", Name: " << product_ptr->getName()
                << ", Description: " << product_ptr->getDescription()
                << ", Amount: " << product_ptr->getAmount()
                << ", Price: " << product_ptr->getPrice() << std::endl;
            }
            std::cout << "Report saving is done." << std::endl;
        }catch(const std::exception &e) {
            std::cerr << "CsvGenerator::generateReport failed with error: " << e.what() << std::endl;
        }
    };
};



#endif //CSVGENERATOR_H
