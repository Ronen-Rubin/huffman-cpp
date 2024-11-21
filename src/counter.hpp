#ifndef COUNTER_HPP
#define COUNTER_HPP

class Counter {
  public:
    int count;

    Counter(int initial);

    void increment();
    void decrement();
};
#endif