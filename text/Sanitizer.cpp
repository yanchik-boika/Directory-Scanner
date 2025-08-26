#include "Sanitizer.h"
#include "../globals/includes.h"

std::string Sanitizer::sanitize(const std::string &word) {
    std::string result;
    for (char ch : word) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            result += std::tolower(ch);
        }
    }
    return result;
}
