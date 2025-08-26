#ifndef AVERAGEPRICEAGGREGATOR_H
#define AVERAGEPRICEAGGREGATOR_H

#include "../interfaces/IAggregator.h"
#include "../managers/ProductManager.h"
class AveragePriceAggregator : public IAggregator{
private:
    std::unordered_map<std::string, std::pair<int, double>> average_price_by_category;
public:
    ~AveragePriceAggregator() = default;

    void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) override;

    void show_result() override;

};



#endif //AVERAGEPRICEAGGREGATOR_H
