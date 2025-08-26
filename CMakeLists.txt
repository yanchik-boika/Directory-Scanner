cmake_minimum_required(VERSION 3.29)
project(Dictionary_Scanner)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dictionary_Scanner main.cpp
        globals/Globals.h
        collectors/TxtFileCollector.h
        interfaces/IFileCollector.h
        sources/FileTextSource.h
        interfaces/ITextSource.h
        text/WordEntry.h
        controllers/ApplicationController.h
        interfaces/IReportGenerator.h
        collectors/CsvFileCollector.h
        text/TextProcessor.h
        controllers/ApplicationController.cpp
        collectors/TxtFileCollector.cpp
        text/Sanitizer.h
        text/Sanitizer.cpp
        managers/DictionaryManager.cpp
        Generators/TxtGenerator.h
        collectors/CsvFileCollector.cpp
        sources/FileCsvSource.h
        csv/Product.h
        csv/CsvProcessor.h
        managers/ProductManager.cpp
        managers/ProductManager.h
        Generators/CsvGenerator.h
        globals/includes.h
        managers/AggregationManager.cpp
        managers/AggregationManager.h
        aggregators/NameAggregator.cpp
        aggregators/NameAggregator.h
        interfaces/IAggregator.h
        aggregators/CategoryAggregator.cpp
        aggregators/CategoryAggregator.h
        aggregators/AmountAggregator.cpp
        aggregators/AmountAggregator.h
        aggregators/CostAggregator.cpp
        aggregators/CostAggregator.h
        aggregators/AveragePriceAggregator.cpp
        aggregators/AveragePriceAggregator.h
        interfaces/IFileProcessor.h
)
