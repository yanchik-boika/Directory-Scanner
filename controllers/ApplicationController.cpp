#include "ApplicationController.h"
#include "../globals/includes.h"
#include "../managers/AggregationManager.h"

//i can add some flag to scanned file to minimize the number of times this file is processed in case there is a rescan during program execution <==> in case new file has been added & i need to get its info
//to do so i can change the name of it or every 10 minutes check the numer of files in working directory...
void ApplicationController::run() {
    AnalyzerEngine analyzerEngine;
    analyzerEngine.buildObjects();

    auto txtFileCollector = analyzerEngine.getTxtFileCollector();
    auto file_text_source = analyzerEngine.getTxtTextSourceReference();

    auto csvFileCollector = analyzerEngine.getCsvFileCollector();
    auto file_csv_source = analyzerEngine.getCsvTextSourceReference();

    auto txt_manager = analyzerEngine.getDictionaryReference();
    auto txt_generator = analyzerEngine.getTextGeneratorReference();

    auto csv_manager =analyzerEngine.getProductManagerReference();
    auto csv_generator = analyzerEngine.getCsvGeneratorReference();

    const std::unordered_map<std::string, WordEntry>* words_map_ptr = nullptr;
    const std::unordered_map<std::string, std::unique_ptr<Product>>* product_map_ptr = nullptr;

    while (true) {
        std::cout << "\n--- Dictionary Scanner ---\n";
        std::cout << "1. Scan .txt files\n";
        std::cout << "2. Generate report\n";
        std::cout << "3. Save report to file\n";
        std::cout << "4. Show TOP 10 most used words\n";
        std::cout << "5. Scan .csv files\n";
        std::cout << "6. Generate product list\n";
        std::cout << "7. Save product report to file\n";
        std::cout << "8. Show products by filter\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an action: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Scanning .txt files from directory: " << data_directory << "\n";
                auto txtFileCollectorFuture = std::async(std::launch::async, [&txtFileCollector]() {
                    return txtFileCollector->collectFiles(data_directory);
                });

                int thread_count = 3;
                std::vector<std::thread> threads;

                for (int i = 0; i < thread_count; ++i) {
                    threads.emplace_back([&file_text_source, &txt_manager]() {
                        return file_text_source->streamToProcessor(*txt_manager);
                    });
                }

                for(auto& thread : threads) {
                    thread.join();
                }

                words_map_ptr = &txt_manager->get_global_dictionary();
                std::cout << "Scanning complete.\n";
                std::cout << "Files have been processed.\n";
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 2: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Displaying report: \n";
                txt_manager->show_dictionary();
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 3: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Saving report to file...\n";
                txt_generator->generateReport(words_map_ptr);
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 4: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "TOP 10 most used words: " << std::endl;
                txt_manager->show_top_words();
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 5: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Scanning .csv files from directory: " << data_directory << "\n";

                auto csvFileCollectorFuture = std::async(std::launch::async, [&csvFileCollector]() {
                    return csvFileCollector->collectFiles(data_directory);
                });

                int thread_count = 3;
                std::vector<std::thread> threads;

                for(int i = 0; i < thread_count; i++) {
                    threads.emplace_back([&file_csv_source, &csv_manager]() {
                        return file_csv_source->streamToProcessor(*csv_manager);
                    });
                }

                for(auto& thread : threads) {
                    thread.join();
                }

                product_map_ptr = &csv_manager->get_product_list();
                std::cout << "Scanning complete.\n";
                std::cout << "Files have been processed.\n";
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 6: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Displaying product's report:\n";
                csv_manager->show_products();
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 7: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Saving product's report to file...\n";
                csv_generator->generateReport(product_map_ptr);
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 8: {
                std::cout << "\n\n-----------------------------------------\n";
                AggregationManager aggregation_manager;
                aggregation_manager.show_options(product_map_ptr);
                std::cout << "-----------------------------------------\n\n";
                break;
            }

            case 0: {
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Exiting the program.\n";
                std::cout << "-----------------------------------------\n\n";
                return;
            }
            default:
                std::cout << "\n\n-----------------------------------------\n";
                std::cout << "Invalid choice. Please try again.\n";
                std::cout << "-----------------------------------------\n\n";
        }
    }
}
