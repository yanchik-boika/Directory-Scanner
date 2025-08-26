#ifndef CSVPROCESSOR_H
#define CSVPROCESSOR_H

#include "../managers/ProductManager.h"
#include "../interfaces/IFileProcessor.h"

#include <unordered_map>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>


class CsvProcessor : public IFileProcessor<ProductManager>{
public:
    void work_with_file(const std::filesystem::path& file_path, ProductManager& manager) {
        try {
            std::ifstream file(file_path);
            if(!file.is_open()) {
                throw std::runtime_error("File could not be opened.");
            }

            std::unordered_map<std::string, std::unique_ptr<Product>> local_product_list;
            std::string line;

            std::getline(file, line);
            while(std::getline(file, line)) {
                std::stringstream ss(line);
                std::string cell;

                auto product = std::make_unique<Product>();

                try {
                    std::getline(ss, cell, ',');
                    if (cell.empty()) throw std::runtime_error("ID is empty.");
                    product->setId(std::stoi(cell));

                    std::getline(ss, cell, ',');
                    if (cell.empty()) throw std::runtime_error("Name is empty.");
                    product->setName(cell);

                    std::getline(ss, cell, ',');
                    product->setDescription(cell);

                    std::getline(ss, cell, ',');
                    if (cell.empty()) throw std::runtime_error("Category is empty.");
                    product->setCategory(cell);

                    std::getline(ss, cell, ',');
                    if (cell.empty()) throw std::runtime_error("Amount is empty.");
                    product->setAmount(std::stoi(cell));

                    std::getline(ss, cell, ',');
                    if (cell.empty()) throw std::runtime_error("Price is empty.");
                    product->setPrice(std::stod(cell));

                    if(!local_product_list.contains(product->getName())) {
                        local_product_list[product->getName()] = std::move(product);
                    }else {
                        local_product_list[product->getName()]->updateAmount(product->getAmount());
                        local_product_list[product->getName()]->updatePrice(product->getPrice());
                    }
                }catch(const std::exception& e) {
                    std::cerr << "Error parsing line in " << file_path << ": " << e.what() << std::endl;
                    continue;
                }
            }

            manager.merge(local_product_list);
        }catch(const std::exception& e) {
            std::cerr << "Error with working on csv file" << file_path << ": " << e.what() << std::endl;
        }
    };

    ~CsvProcessor() = default;

};



#endif //CSVPROCESSOR_H
