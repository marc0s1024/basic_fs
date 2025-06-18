#pragma once

#include "Directory.h"
#include <string>
#include <vector>

class FileSystem {
private:
    Directory* root; // Root directory of the file system
    Directory* cwd; // Current working directory

public:
    // lifecycle
    FileSystem();
    ~FileSystem();

    // state query
    std::string pwd() const; // get current working directory path

    // directory manipulation
    bool mkdir(const std::string& name); // create a new directory in the current directory
    bool cd(const std::string& path); // change current directory to the specified path
    std::vector<std::string> ls() const; // list contents of the current directory
    
    // add touch, rm, cat, write, append as needed
};