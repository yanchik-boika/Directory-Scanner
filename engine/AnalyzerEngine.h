#ifndef ANALYZERENGINE_H
#define ANALYZERENGINE_H

#include <iostream>

#include "../Generators/TxtGenerator.h"
#include "../Generators/CsvGenerator.h"
#include "../sources/FileTextSource.h"
#include "../sources/FileCsvSource.h"
#include "../managers/DictionaryManager.h"
#include "../managers/ProductManager.h"
#include "../collectors/TxtFileCollector.h"
#include "../collectors/CsvFileCollector.h"

class AnalyzerEngine {
private:
    std::pair<std::shared_ptr<DictionaryManager>, std::shared_ptr<TxtGenerator>> dictionary_txtGenerator_references;
    std::pair<std::shared_ptr<TxtFileCollector>, std::shared_ptr<FileTextSource>> collector_txt_source_references;

    std::pair<std::shared_ptr<ProductManager>, std::shared_ptr<CsvGenerator>> product_csvGenerator_references;
    std::pair<std::shared_ptr<CsvFileCollector>, std::shared_ptr<FileCsvSource>> collector_csv_source_references;


public:

    void buildObjects() {
        dictionary_txtGenerator_references.first = std::make_shared<DictionaryManager>();
        dictionary_txtGenerator_references.second = std::make_shared<TxtGenerator>();

        collector_txt_source_references.first = std::make_shared<TxtFileCollector>();
        collector_txt_source_references.second = std::make_shared<FileTextSource>();


        product_csvGenerator_references.first = std::make_shared<ProductManager>();
        product_csvGenerator_references.second = std::make_shared<CsvGenerator>();

        collector_csv_source_references.first = std::make_shared<CsvFileCollector>();
        collector_csv_source_references.second = std::make_shared<FileCsvSource>();

    }

    std::shared_ptr<DictionaryManager> getDictionaryReference() {
        return this->dictionary_txtGenerator_references.first;
    }

    std::shared_ptr<TxtGenerator> getTextGeneratorReference(){
        return this->dictionary_txtGenerator_references.second;
    }

    std::shared_ptr<TxtFileCollector> getTxtFileCollector() {
        return this->collector_txt_source_references.first;
    }
    std::shared_ptr<FileTextSource> getTxtTextSourceReference() {
        return this->collector_txt_source_references.second;
    }

    std::shared_ptr<ProductManager> getProductManagerReference() {
        return this->product_csvGenerator_references.first;
    }
    std::shared_ptr<CsvGenerator> getCsvGeneratorReference() {
        return this->product_csvGenerator_references.second;
    }

    std::shared_ptr<CsvFileCollector> getCsvFileCollector() {
        return this->collector_csv_source_references.first;
    }
    std::shared_ptr<FileCsvSource> getCsvTextSourceReference() {
        return this->collector_csv_source_references.second;
    }
};



#endif //ANALYZERENGINE_H
