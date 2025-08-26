#ifndef NAMEAGGREGATOR_H
#define NAMEAGGREGATOR_H
#include "../interfaces/IAggregator.h"
#include "../managers/ProductManager.h"
#include <vector>


class NameAggregator : public IAggregator{
private:
    std::vector<std::pair<std::string, Product*>> filtered_products;
public:
    ~NameAggregator() = default;

    void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) override;

    void show_result() override;

};





#endif //NAMEAGGREGATOR_H
