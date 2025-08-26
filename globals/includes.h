#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <sstream>
#include <fstream>

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>

#include <cmath>

#include <filesystem>
#include <thread>
#include <mutex>
#include <atomic>
#include <memory>
#include <future>

#include "../managers/DictionaryManager.h"
#include "../managers/ProductManager.h"
#include "../managers/AggregationManager.h"

#include "../globals/Globals.h"

#include "../aggregators/NameAggregator.h"
#include "../aggregators/CategoryAggregator.h"
#include "../aggregators/AmountAggregator.h"
#include "../aggregators/CostAggregator.h"
#include "../aggregators/AveragePriceAggregator.h"

#include "../interfaces/IFileCollector.h"
#include "../interfaces/IReportGenerator.h"
#include "../interfaces/ITextSource.h"
#include "../interfaces/IAggregator.h"

#include "../collectors/TxtFileCollector.h"
#include "../collectors/CsvFileCollector.h"

#include "../controllers/ApplicationController.h"

#include "../csv/Product.h"
#include "../csv/CsvProcessor.h"

#include "../engine/AnalyzerEngine.h"

#include "../Generators/TxtGenerator.h"
#include "../Generators/CsvGenerator.h"

#include "../sources/FileTextSource.h"
#include "../sources/FileCsvSource.h"

#include "../text/TextProcessor.h"
#include "../text/Sanitizer.h"
#include "../text/WordEntry.h"

#endif //INCLUDES_H
