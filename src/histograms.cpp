#include "histograms.hpp"
#include <unordered_map>

//function will recieve string by refrence and output an order_map by value

std::unordered_map<std::string, int> histogram(const std::string &str){
std::unordered_map<std::string, int> histogram;
for (int i = 0; i < str.size(); i++){ 
            //printf("%d\n", i);
            std::string symbol = str.substr(i,  1);
            if (histogram[symbol]) {//.at() does bounds check, [] does not. 
                histogram[symbol]++; //could do histogram.at(key) but this bad becaus ebound checking stops loop
            }
            else {
                histogram[symbol] = 1;
            }
        }
        for (const auto &pair : histogram) {//range based loop. : looks for iterable. auto means "infer type for me plz"
            printf("Key: %s, Value: %d\n", pair.first.c_str(), pair.second);
        }
    return histogram;
}
