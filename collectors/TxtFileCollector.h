#ifndef TXTFILECOLLECTOR_H
#define TXTFILECOLLECTOR_H

#include "../interfaces/IFileCollector.h"
#include <filesystem>
#include <vector>

class TxtFileCollector : public IFileCollector {
public:
    void collectFiles(const std::filesystem::path& dir) const override;
    void push_batch_to_global(std::vector<std::filesystem::path>& local_paths) const override;
};



#endif //TXTFILECOLLECTOR_H
