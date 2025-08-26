#include "./globals/includes.h"

std::vector<std::filesystem::path> txt_global_paths;
std::mutex txt_global_paths_mutex;
std::condition_variable txt_global_condition;

std::vector<std::filesystem::path> csv_global_paths;
std::mutex csv_global_paths_mutex;
std::condition_variable csv_global_condition;

std::atomic<bool> scanning_done{false};

const std::filesystem::path data_directory = std::filesystem::absolute("data");
const std::filesystem::path text_output_path = std::filesystem::absolute("output/words_report.txt");
const std::filesystem::path csv_output_path = std::filesystem::absolute("output/product_report.txt");



int main()
{
    ApplicationController app;
    app.run();
    return 0;
}