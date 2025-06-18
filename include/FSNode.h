#pragma once
#include <string>

class Directory; // forward declaration

class FSNode {
    protected:
        std::string name;
        Directory* parent; // pointer to parent directory

    public:
        // constructor and virtual destructor
        FSNode(const std::string& name, Directory* parent);
        virtual ~FSNode();

    // pure virtual: must override in subclasses
    virtual bool isDirectory() const = 0;

    // accessors
    const std::string& getName() const;
    std::string getPath() const;
    
    Directory* getParent() const { 
        return parent; 
    }
};