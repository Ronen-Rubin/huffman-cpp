#include "files.hpp" //only include header files, compilation errors if its not just header files.
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    // std::unordered_map<std::string, int> histogram;
    std::string path = argv[1]; // alternative path(argv[1])

    // std::string source = read_file(argv[1]);
    // passed argv[1] by value/refrence if use other line
    // We now knows its treating path as a C++
    std::string source = read_file(path);

    // output of readfile is strong. It's being copied into the var source, could be big.
    std::printf("%s", source.c_str());

    return 0;
}
