#include "files.hpp"
#include <iostream> //in brackets because then preprocessor looks in std library module
#include <fstream>
#include <sstream>

//std::string read_file(std::string path){
std::string read_file(const std::string &path){

    std::ifstream file(path.c_str());
    std::stringstream buffer; 

    buffer << file.rdbuf();
    //std::string str = buffer.str(); // would assign to str, unused
    return buffer.str(); //take the stringstream and give me back the string it represents. 

}
