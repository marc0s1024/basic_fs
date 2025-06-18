#include "../include/File.h"

File::File(const std::string& name, Directory* parent)
    : FSNode(name, parent), content() {}

const std::string& File::read() const {
    return content;
}

void File::write(const std::string& data, bool append) {
    if (append) {
        content += data;
    } else {
        content = data;
    }
}