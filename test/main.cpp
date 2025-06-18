#include "../include/FileSystem.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// split on a single character delimiter, skipping empty segments
static std::vector<std::string> split(const std::string& s, char delim = ' ') {
  std::vector<std::string> tokens;
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    if (!item.empty()) {
      tokens.push_back(item);
    }
  }
  return tokens;
}

int main() {
  FileSystem fs;
  std::string line;
  
  while(true) {
    // prompt
    std::cout << fs.pwd() << " $ ";
    if (!std::getline(std::cin, line)) break; // EOF or error

    auto args = split(line);
    if (args.empty()) continue; // ignore empty input

    const std::string& cmd = args[0];
    if (cmd == "exit" || cmd == "quit") {
      break;
    }
    else if (cmd == "pwd") {
      std::cout << fs.pwd() << "\n";
    }
    else if (cmd == "ls") {
      for (auto& name : fs.ls()) {
        std::cout << name << " ";
      }
      std::cout << "\n";
    }
    else if (cmd == "mkdir") {
      if (args.size() < 2) {
        std::cout << "mkdir: missing operand\n";
      } else if (!fs.mkdir(args[1])) {
          std::cout << "mkdir: cannot create '" << args[1]
                    << "': File exists\n";
      }
    }
    else if (cmd == "cd") {
      if (args.size() < 2) {
        std::cout << "cd: missing operand\n";
      } else if (!fs.cd(args[1])) {
        std::cout << "cd: no such file or directory: "
                  << args[1] << "\n";
      }
    }
    else {
      std::cout << cmd << ": command not found\n";
    }
  }

  return 0;
}