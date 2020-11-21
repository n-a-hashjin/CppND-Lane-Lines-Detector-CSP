#include "file_handle.h"
#include <filesystem>

FileHandle::FileHandle(){}

FileHandle::~FileHandle(){}

void FileHandle::setFilenames(std::string path){
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        fileLists_.push_back(entry.path());
    }
}

std::string FileHandle::getNextfilename(){
    std::string filename;
    if (!fileLists_.empty())
    {
        filename = fileLists_.back();
        fileLists_.pop_back();
    }
    return filename;
}

bool FileHandle::empty() {return fileLists_.empty();}