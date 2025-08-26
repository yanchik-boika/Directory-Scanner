#ifndef IAGGREGATOR_H
#define IAGGREGATOR_H

#include "../managers/ProductManager.h"

class IAggregator {
public:
    virtual ~IAggregator() = default;

    virtual void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) = 0;
    virtual void show_result() = 0;

};




#endif //IAGGREGATOR_H
