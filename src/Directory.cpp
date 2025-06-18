#include "../include/Directory.h"
#include <algorithm> // for std::find_if

Directory::Directory(const std::string& name, Directory* parent)
    : FSNode(name, parent) {}

Directory::~Directory() {
    // recursively delete all children
    for (FSNode* child : children) {
        delete child;
    }
    children.clear();
}

void Directory::add(FSNode* node) {
    children.push_back(node);
}

FSNode* Directory::find(const std::string& name) const {
    for (FSNode* child : children) {
        if (child->getName() == name) {
            return child;
        }
    }
    return nullptr; // not found
}

bool Directory::remove(const std::string& name) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it; // free that subtree
            children.erase(it); // remove pointer from vector
            return true; // successfully removed
        }
    }
    return false; // not found
}

const std::vector<FSNode*>& Directory::list() const {
    return children;
}

