#include "DictionaryManager.h"
#include "../globals/includes.h"


void DictionaryManager::merge(std::unordered_map<std::string, WordEntry>& local_dictionary, const std::filesystem::path& path) {

    std::lock_guard<std::mutex> lock(dictMutex);
    for(const auto& entry : local_dictionary) {
        if(globalDictionary[entry.first].get_frequency() == 0) {
            globalDictionary[entry.first].set_word(entry.first);
            globalDictionary[entry.first].set_frequency(entry.second.get_frequency());
            globalDictionary[entry.first].add_occurrence(path.filename());
        }else {
            globalDictionary[entry.first].add_occurrence(path.filename());
            globalDictionary[entry.first].add_frequency_to_existing(entry.second.get_frequency());
        }
    }
}

void DictionaryManager::show_dictionary() const {
    if(this->globalDictionary.size() == 0) {
        std::cout << "You haven't scan the directory. Dictionary is empty." << std::endl;
        return;
    }else {
        for(auto& entry : this->globalDictionary) {
            int freq = entry.second.get_frequency();
            std::cout << "Word: " << entry.first << " Frequency: " << freq << " ";
            std::cout << "Accurance: [ ";
            for(auto source : entry.second.get_accurence()) {
                std::cout << source << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
}


void DictionaryManager::show_top_words() const {
    if(this->globalDictionary.size() == 0) {
        std::cout << "You haven't scan the directory. Dictionary is empty." << std::endl;
        return;
    }
    std::vector<std::pair<std::string, WordEntry>> sorted_entries(globalDictionary.begin(), globalDictionary.end());

    // Step 2: Sort by frequency descending
    std::sort(sorted_entries.begin(), sorted_entries.end(),
              [](const auto& a, const auto& b) {
                  return a.second.get_frequency() > b.second.get_frequency();
              });

    std::cout << "--- Top 10 Most Frequent Words ---\n";
    int count = 0;
    for (const auto& [word, entry] : sorted_entries) {
        if (count++ >= 10) break;

        std::cout << "Word: " << word
                  << " | Frequency: " << entry.get_frequency()
                  << " | Sources: ";
        for (const auto& src : entry.get_accurence()) {
            std::cout << src << ", ";
        }
        std::cout << "\n";
    }
}

