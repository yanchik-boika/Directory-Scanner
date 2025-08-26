#ifndef IREPORTGENERATOR_H
#define IREPORTGENERATOR_H

#include "../managers/DictionaryManager.h"
#include "../managers/ProductManager.h"

// class IReportGenerator {
// public:
//   virtual ~IReportGenerator() = default;
//   virtual void generateReport(const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map) const = 0;
// };



template <typename T>
class IReportGenerator {
public:
    virtual ~IReportGenerator() = default;
    virtual void generateReport(const T* data) const = 0;
};

#endif //IREPORTGENERATOR_H
