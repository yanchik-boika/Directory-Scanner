#ifndef COSTAGGREGATOR_H
#define COSTAGGREGATOR_H

#include "../interfaces/IAggregator.h"
#include "../managers/ProductManager.h"
#include <vector>

class CostAggregator : public IAggregator {
private:
    double total_products_cost;
public:
    ~CostAggregator() = default;

    void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) override;

    void show_result() override;


};



#endif //COSTAGGREGATOR_H
