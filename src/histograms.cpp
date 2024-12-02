#include "histograms.hpp"
#include <unordered_map>

//function will receive string by refrence and output an order_map by value

std::unordered_map<std::string, int> histogram(const std::string &str){//Here histogram is the name of the function.
std::unordered_map<std::string, int> my_histogram; //Here I chose initilaize my_histogram to emphasise that this is the chosen name of a variable.
for (int i = 0; i < str.size(); i++){ 
            //printf("%d\n", i);
            std::string symbol = str.substr(i,  1);
            if (my_histogram[symbol]) {//check if symbol already in histogram keys(.at() does bounds check, [] does not.)
                my_histogram[symbol]++; //could do histogram.at(key) but this bad because bound checking stops loop
            }
            else {
                my_histogram[symbol] = 1;
            }
        }
        //print histogram for debugging:
        for (const auto &pair : my_histogram) {//range based loop. : looks for iterable. auto means "infer type for me plz"
        // without auto would need to do something like: for (std::unordered_map<std::string, int>::const_iterator it = my_histogram.begin(); it != my_histogram.end(); ++it)
            printf("Key: %s, Value: %d\n", pair.first.c_str(), pair.second);
        }
    return my_histogram;
}
