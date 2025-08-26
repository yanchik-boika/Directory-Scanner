#ifndef AMOUNTAGGREGATOR_H
#define AMOUNTAGGREGATOR_H

#include "../interfaces/IAggregator.h"
#include "../managers/ProductManager.h"

class AmountAggregator : public IAggregator{
private:
    int amount;
public:
    ~AmountAggregator() = default;

    void aggregate(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) override;

    void show_result() override;

    void set_amount(int amount) {
        this->amount = amount;
    }
    int get_amount() {
        return this->amount;
    }

};



#endif //AMOUNTAGGREGATOR_H
