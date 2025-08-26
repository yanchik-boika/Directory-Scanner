#ifndef IFILECOLLECTOR_H
#define IFILECOLLECTOR_H

#include <filesystem>
#include <vector>

class IFileCollector {
public:
  virtual ~IFileCollector() = default;
  virtual void collectFiles(const std::filesystem::path& directory) const = 0;
  virtual void push_batch_to_global(std::vector<std::filesystem::path>& local_paths) const = 0;
};



#endif //IFILECOLLECTOR_H
