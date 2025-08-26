#ifndef WORDENTRY_H
#define WORDENTRY_H


#include <unordered_set>
#include <string>


class WordEntry {
private:
    std::string word;
    int frequency = 0;
    std::unordered_set<std::string> sources;
public:

    WordEntry() = default;
    WordEntry(const std::string& w) : word(w), frequency(1) {}

    void add_occurrence(const std::string& source) {
        sources.insert(source);
    }
    const std::unordered_set<std::string>& get_accurence() const{
        return this->sources;
    }

    std::string get_word() const {
        return word;
    }
    void set_word(const std::string& w) {
        this->word = w;
    }

    int get_frequency() const {
        return frequency;
    }
    void add_frequency() {
        this->frequency++;
    }
    void add_frequency_to_existing(int plus_frequency) {
        this->frequency += plus_frequency;
    }
    void set_frequency(int frequency) {
        this->frequency = frequency;
    }
};



#endif //WORDENTRY_H
