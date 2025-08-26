#ifndef CATEGORYAGGREGATOR_H
#define CATEGORYAGGREGATOR_H

#include "../interfaces/IAggregator.h"
#include "../managers/ProductManager.h"
#include <vector>

class CategoryAggregator : public IAggregator{
private:
    std::vector<std::pair<std::string, Product*>> filtered_products;
public:
    ~CategoryAggregator() = default;

    void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) override;

    void show_result() override;

};



#endif //CATEGORYAGGREGATOR_H
