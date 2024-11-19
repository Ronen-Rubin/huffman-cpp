#include <string>
#include "counter.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    Counter counter(10);
    counter.increment();
    counter.increment();
    counter.increment();

    printf("%d\n", counter.count);

    return 0;
}
