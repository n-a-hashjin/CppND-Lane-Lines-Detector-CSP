#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include <vector>
#include <string>

class FileHandle {
  public:
    FileHandle();
    ~FileHandle();
    void setFilenames(std::string path);
    std::string getNextfilename();
    bool empty();
  private:
    std::vector<std::string> fileLists_{};
};
#endif