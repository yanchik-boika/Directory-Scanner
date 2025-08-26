#ifndef DICTIONARYMANAGER_H
#define DICTIONARYMANAGER_H


#include <unordered_map>
#include <filesystem>
#include <mutex>
#include "../text/WordEntry.h"

class DictionaryManager {
private:
    std::unordered_map<std::string, WordEntry> globalDictionary;
    std::mutex dictMutex;

public:

    void merge(std::unordered_map<std::string, WordEntry>& local_dictionary, const std::filesystem::path& path);

    const std::unordered_map<std::string, WordEntry>& get_global_dictionary() const{
        return this->globalDictionary;
    }

    void show_dictionary() const;

    void show_top_words() const;

};



#endif
