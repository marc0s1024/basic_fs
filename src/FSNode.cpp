#include "../include/FSNode.h"
#include "../include/Directory.h" // needed for parent traversal


FSNode::FSNode(const std::string& n, Directory* p): name(n), parent(p) {}

FSNode::~FSNode() = default;

const std::string& FSNode::getName() const {
    return name;
}

std::string FSNode::getPath() const {
    if (!parent) {
        return name; // root node: name should be "/" so returns "/"
    }
    // otherwise build path based on parent
    const std::string parentPath = parent->getPath();
    if (parentPath == "/") {
        return "/" + name; // special case: avoid double slashes
    } else {
        return parentPath + "/" + name; // concatenate parent path with current node name
    }
}