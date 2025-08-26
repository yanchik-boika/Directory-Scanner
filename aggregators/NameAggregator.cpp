#include "NameAggregator.h"
#include "../globals/includes.h"

void NameAggregator::aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {
    filtered_products.clear();

    for (const auto& [name, product_ptr] : *product_map) {
        if (product_ptr) {
            filtered_products.emplace_back(name, product_ptr.get());
        }
    }

    std::sort(filtered_products.begin(), filtered_products.end(),
              [](const auto& a, const auto& b) {
                  return a.first < b.first;
              });
}


void NameAggregator::show_result() {

    std::cout << "\n-----------------------------------------\n";

    std::cout << "Filtered products by name: " << std::endl;

    if (filtered_products.empty()) {
        std::cout << "No products to display.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    for (const auto& [name, product] : filtered_products) {
        std::cout << "Name: " << name
                  << ", Category: " << product->getCategory()
                  << ", Amount: " << product->getAmount()
                  << ", Price: " << product->getPrice()
                  << "\n";
    }
}
