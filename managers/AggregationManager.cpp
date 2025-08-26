#include "AggregationManager.h"
#include "../globals/includes.h"

void AggregationManager::show_options(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {
    if(!product_map || product_map->empty()) {
        std::cout << "No products available. You have to scan the directory otherwise it is empty." << std::endl;
        return;
    }
    std::cout << "----- Available filters -----\n";
    std::cout << "1. Alphabetical sorting by name\n";
    std::cout << "2. Filter by category\n";
    std::cout << "3. Show total amount of product\n";
    std::cout << "4. Show total cost of product\n";
    std::cout << "5. Average price for category\n\n";

    std::cout << " Enter filter you want to use for products: ";
    std::string sfilter;
    std::cin >> sfilter;
    int ifilter = std::stoi(sfilter);
    this->decider(ifilter, product_map);
}

void AggregationManager::decider(int& choice, const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) {
    CostAggregator cost_aggregator;
    switch (choice) {

        case 1: {
            NameAggregator name_aggregator;
            name_aggregator.aggregate(product_map);
            name_aggregator.show_result();
            break;
        }

        case 2: {
            CategoryAggregator category_aggregator;
            category_aggregator.aggregate(product_map);
            category_aggregator.show_result();
            break;
        }

        case 3: {
            AmountAggregator amount_aggregator;
            amount_aggregator.aggregate(product_map);
            amount_aggregator.show_result();
            break;
        }

        case 4: {
            CostAggregator cost_aggregator;
            cost_aggregator.aggregate(product_map);
            cost_aggregator.show_result();
            break;
        }

        case 5: {
            AveragePriceAggregator average_price_aggregator;
            average_price_aggregator.aggregate(product_map);
            average_price_aggregator.show_result();
            break;
        }
    }
}