#include "AmountAggregator.h"
#include "../globals/includes.h"


void AmountAggregator::aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {
    // auto& product_map = manager.get_product_list();

    this->amount = product_map->size();
}

void AmountAggregator::show_result() {
    std::cout << "\n-----------------------------------------\n";
    std::cout << "Total amount of products: " << this->amount << std::endl;
}

