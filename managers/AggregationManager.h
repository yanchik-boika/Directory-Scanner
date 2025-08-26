#ifndef AGGREGATIONMANAGER_H
#define AGGREGATIONMANAGER_H
#include "../managers/ProductManager.h"


//this class will decide which aggregator to use by category, by name, etc.


class AggregationManager {
public:
    void show_options(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map);
    void decider(int& choice, const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map);
    ~AggregationManager() = default;


};



#endif //AGGREGATIONMANAGER_H
