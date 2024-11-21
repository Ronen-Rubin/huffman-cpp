#ifndef FILES_HPP
#define FILES_HPP

#include <string>

//std::string read_file(std::string path); //path is passed by value here
//std::string read_file(std::string &path); //path is passed by refrence here
std::string read_file(const std::string &path); //path is passed by refrence, but because mutuable define as not changable (const) once entered scope.
#endif