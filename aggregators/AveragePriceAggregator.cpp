#include "AveragePriceAggregator.h"
#include "../globals/includes.h"


void AveragePriceAggregator::aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {
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
        std::cout << "\n\n Please, enter category for filter. " << std::endl;
        std::cout << "Available categories: [";
        for (const auto& category : category_keys) {
            std::cout << " " << category << ", ";
        }
        std::cout << " ]" << std::endl;
        std::cout << " Choose category for filter: "; std::cin >> filter;

        if(category_keys.contains(filter)) {
            valid_filter = true;
            break;
        }else{
            std::cout << "Sorry, the filter doesn't exist." << std::endl;
        }
    }
    if (valid_filter) {
        std::cout << "Filter accepted: " << filter << std::endl;
        this->average_price_by_category.clear();

        for (const auto& [name, product_ptr] : *product_map) {
            if (product_ptr && product_ptr->getCategory() == filter) {
                average_price_by_category[filter].first += product_ptr->getAmount();
                average_price_by_category[filter].second += (product_ptr->getPrice() * product_ptr->getAmount());
            }
        }
    } else {
        std::cout << "Failed to enter a valid category after 3 attempts." << std::endl;
        return;
    }

}

void AveragePriceAggregator::show_result() {
    std::cout << "\n\n-----------------------------------------\n";

    if (average_price_by_category.empty()) {
        std::cout << "No products to display.\n";
        return;
    }
    std::cout << "Average price by selected category: " << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& [name, product] : average_price_by_category) {
        std::cout << "Category: " << name
        << ", Average price: " << ( product.second / product.first) << "\n";
    }

}
