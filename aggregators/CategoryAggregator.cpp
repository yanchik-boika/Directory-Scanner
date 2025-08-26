#include "CategoryAggregator.h"
#include "../globals/includes.h"



void CategoryAggregator::aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {

    std::set<std::string> category_keys;
    for (const auto& [name, product_ptr] : *product_map) {
        if (product_ptr) {
            category_keys.insert(product_ptr->getCategory());
        }
    }

    std::string filter;
    bool valid_filter = false;
    for(int i = 0; i < 3; i++) {
        std::cin.ignore();
        std::cout << "\n\nPlease, enter category for filter. " << std::endl;
        std::cout << "Available categories: [";
        for (const auto& category : category_keys) {
            std::cout << " " << category << ", ";
        }
        std::cout << " ]\n" << std::endl;
        std::cout << " Choose category for filter: ";
        std::cin >> filter;

        if(category_keys.contains(filter)) {
            valid_filter = true;
            break;
        }else{
            std::cout << "Sorry, the filter doesn't exist." << std::endl;
        }
    }
    if (valid_filter) {
        std::cout << "Filter accepted: " << filter << std::endl;
        this->filtered_products.clear();
        for (const auto& [name, product_ptr] : *product_map) {
            if (product_ptr && product_ptr->getCategory() == filter) {
                filtered_products.emplace_back(name, product_ptr.get());
            }
        }
    } else {
        std::cout << "Failed to enter a valid category after 3 attempts." << std::endl;
        return;
    }
}


void CategoryAggregator::show_result() {
    std::cout << "\n\n-----------------------------------------\n";

    if (filtered_products.empty()) {
        std::cout << "No products to display.\n";
        return;
    }

    std::cout << "Filtered products by category: " << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& [name, product] : filtered_products) {
        std::cout << "Name: " << name
                  << ", Category: " << product->getCategory()
                  << ", Amount: " << product->getAmount()
                  << ", Price: " << product->getPrice()
                  << "\n";
    }
}
