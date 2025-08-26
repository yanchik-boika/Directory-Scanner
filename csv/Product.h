#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <cmath>


class Product {

private:
    int id;
    std::string name;
    std::string description;
    std::string category;
    int amount;
    double price;

public:

    void setId(int id) {
        this->id = id;
    }
    int getId() {
        return this->id;
    }

    void setName(std::string name) {
        this->name = name;
    }
    std::string getName() {
        return this->name;
    }

    void setDescription(std::string description) {
        this->description = description;
    }
    std::string getDescription() {
        return this->description;
    }

    void setCategory(std::string category) {
        this->category = category;
    }
    std::string getCategory() {
        return this->category;
    }

    void setAmount(int amount) {
        this->amount = amount;
    }
    int getAmount() {
        return this->amount;
    }

    void setPrice(double price) {
        this->price = price;
    }
    double getPrice() {
        return this->price;
    }

    void updateAmount(int amount) {
        this->amount += amount;
    }
    void updatePrice(double price) {
        double avg = ((this->price) + price) / 2.0;
        this->price = std::round(avg * 100.0) / 100.0;
    }
};



#endif //PRODUCT_H
