#pragma once
#include "FSNode.h"

class File : public FSNode {
private:
    std::string content;

public:
    File(const std::string& name, Directory* parent);
    ~File() override = default;

    bool isDirectory() const override { return false; }

    // read/write
    const std::string& read() const;
    void write(const std::string& data, bool append = true);
};