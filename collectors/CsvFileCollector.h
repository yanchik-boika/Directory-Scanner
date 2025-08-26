#ifndef CSVFILECOLLECTOR_H
#define CSVFILECOLLECTOR_H

#include "../interfaces/IFileCollector.h"
#include <filesystem>
#include <vector>

class CsvFileCollector : public IFileCollector{
public:
    void collectFiles(const std::filesystem::path& dir) const override;
    void push_batch_to_global(std::vector<std::filesystem::path>& local_paths) const override;

};



#endif //CSVFILECOLLECTOR_H
