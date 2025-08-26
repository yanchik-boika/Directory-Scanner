#ifndef GLOBALS_H
#define GLOBALS_H

extern std::vector<std::filesystem::path> txt_global_paths;
extern std::mutex txt_global_paths_mutex;
extern std::condition_variable txt_global_condition;
extern std::atomic<bool> scanning_done;



extern std::vector<std::filesystem::path> csv_global_paths;
extern std::mutex csv_global_paths_mutex;
extern std::condition_variable csv_global_condition;

extern const std::filesystem::path data_directory;
extern const std::filesystem::path text_output_path;
extern const std::filesystem::path csv_output_path;



#endif //GLOBALS_H
