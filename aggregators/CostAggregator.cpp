#include "CostAggregator.h"
#include "../globals/includes.h"

void CostAggregator::aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {

    // auto& product_map = manager.get_product_list();

    for(const auto& [name, product] : *product_map) {
        total_products_cost += product->getAmount() * product->getPrice();
    }
}

void CostAggregator::show_result() {
    std::cout << "\n-----------------------------------------\n";
    std::cout << "Total cost of all products in stock: $" << total_products_cost  << ""<< std::endl;
}

