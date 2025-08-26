#ifndef IFILEPROCESSOR_H
#define IFILEPROCESSOR_H

#include <filesystem>

template <typename T>
class IFileProcessor {
public:
    ~IFileProcessor() = default;

    virtual void work_with_file(const std::filesystem::path& file, T& manager) = 0;

};


#endif //IFILEPROCESSOR_H
