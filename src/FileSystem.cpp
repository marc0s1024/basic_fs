#include "../include/FileSystem.h"
#include <sstream> // for std::stringstream
#include <iterator> // for std::istream_iterator

// constructor: initializes root and current directory
FileSystem::FileSystem() {
    // use "/" as the name for the root directory
    root = new Directory("/", nullptr); // root has no parent
    cwd = root; // start at root
}

// destructor: cleans up allocated memory
FileSystem::~FileSystem() {
    delete root; // deleting root will recursively delete all children
}

// pwd() ask cwd for its path
std::string FileSystem::pwd() const {
    return cwd->getPath();
}

// mkdir creates a new directory in cwd 
bool FileSystem::mkdir(const std::string& name) {
    // prevent name collisions
    if (cwd->find(name) != nullptr) {
        return false; // name already exists
    }
    // create and add new directory node
    Directory* sub = new Directory(name, cwd);
    cwd->add(sub);
    return true;
}

std::vector<std::string> FileSystem::ls() const {
    std::vector<std::string> names;
    for (FSNode* child : cwd->list()) {
        names.push_back(child->getName());
    }
    return names;
}

bool FileSystem::cd(const std::string& path) {
    // determine starting point
    Directory* dir = (path.size() > 0 && path[0] == '/') ? root : cwd;

    // split on '/'
    std::stringstream ss(path);
    std::string segment;
    while (std::getline(ss, segment, '/')) {
        if (segment.empty() || segment == ".") {
            // stay in current directory
            continue;
        }
        if (segment == "..") {
            if (dir->getPath() != "/") {
                dir = dynamic_cast<Directory*>(dir->getParent());
            }
        } else {
            FSNode* node = dir->find(segment);
            // must exist and be a directory
            Directory* nextDir = dynamic_cast<Directory*>(node);
            if (!nextDir) {
                return false; // not found or not a directory
            }
            dir = nextDir;
        }
    }

    // success: update cwd
    cwd = dir;
    return true;
}
