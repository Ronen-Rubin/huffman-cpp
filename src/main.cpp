#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "files.hpp"  //only include header files, compilation errors if its not just header files.

int main(int argc, char *argv[]) {//suspect: passing argv[1] as C string causes ≡°ƒ2O, implicit conversion. This was not the problem
    if (argc == 2) {
        //std::unordered_map<std::string, int> histogram;
        std::string path = argv[1]; // alternative path(argv[1])
        // std::string source = read_file(argv[1]);//passed argv[1] by value/refrence if use other line
        std::string source = read_file(path);// We now knows its treating path as a C++
        printf("%s", source); //output of readfile is strong. It's being copied into the var source, could be big.




 
        // ...

        return 0;
    }

    return 1;
}
