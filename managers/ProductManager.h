#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <unordered_map>
#include <filesystem>
#include <mutex>
#include "../csv/Product.h"

class ProductManager {
private:
    std::unordered_map<std::string, std::unique_ptr<Product>> global_product_list;
    std::mutex product_mutex;

public:
    //maybe here is better to pass a const string reference to merge method?
    void merge(std::unordered_map<std::string, std::unique_ptr<Product>>& local_products_list);

    std::unordered_map<std::string, std::unique_ptr<Product>>& get_product_list(){
        return this->global_product_list;
    }

    void show_products() const;
};



#endif //PRODUCTMANAGER_H
