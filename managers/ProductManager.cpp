#include "ProductManager.h"
#include "../globals/includes.h"

void ProductManager::merge(std::unordered_map<std::string, std::unique_ptr<Product>>& local_products_list) {
    std::lock_guard<std::mutex> lock(product_mutex);
    for(auto& [name, product_ptr] : local_products_list) {
        if(!global_product_list.contains(name)) {
            global_product_list[name] = std::move(product_ptr);
        }else {
            auto old_amount = global_product_list[name]->getAmount();
            auto old_price = global_product_list[name]->getPrice();
            global_product_list[name]->updateAmount(product_ptr->getAmount());
            global_product_list[name]->setPrice(((old_amount * old_price) + (product_ptr->getAmount() * product_ptr->getPrice())) / (old_amount + product_ptr->getAmount()));
        }
    }
    local_products_list.clear();
}

void ProductManager::show_products() const {
    if(this->global_product_list.size() == 0) {
        std::cout << "You haven't scan the directory. Product list is empty." << std::endl;
        return;
    }
    for(auto& [name, product_ptr] : global_product_list) {
        std::cout << "ID: " << product_ptr->getId()
        << " Name: " << product_ptr->getName()
        << " Description: " << product_ptr->getDescription()
        << " Category: " << product_ptr->getCategory()
        << " Amount: " << product_ptr->getAmount()
        << " Price: " << product_ptr->getPrice() << std::endl;
    }
    std::cout << std::endl;
}


