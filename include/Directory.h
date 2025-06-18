#pragma none
#include "FSNode.h"
#include <vector>

class Directory : public FSNode {
private:
    std::vector<FSNode*> children; // vector to hold child nodes

public:
    // constructor and destructor
    Directory(const std::string& name, Directory* parent);
    ~Directory() override;

    // type query
    bool isDirectory() const override { return true; }

    // child manipulation
    void add(FSNode* node);
    FSNode* find(const std::string& name) const;
    bool remove(const std::string& name);

    // listing
    const std::vector<FSNode*>& list() const;
};