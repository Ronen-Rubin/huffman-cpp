#include "counter.hpp"

Counter::Counter(int initial): count(initial) {
    
}

void Counter::increment () {
    count++;
}

void Counter::decrement () {
    count--;
}
