#include "files.hpp"
#include <fstream>
#include <iostream> //in brackets because then preprocessor looks in std library module
#include <sstream>

//std::string read_file(std::string path){
std::string read_file(const std::string &path){//I defined function read_file

    std::ifstream file(path.c_str()); //creates stream
    std::stringstream buffer; //defines/ initlizes buffer

    buffer << file.rdbuf(); //reads stream into buffer
    //std::string str = buffer.str(); // would assign to str, unused
    return buffer.str(); //take the stringstream and give me back the string it represents. 

    // take the stringstream and give me back the string it represents.
    return buffer.str();
}
