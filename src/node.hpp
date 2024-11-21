#ifndef NODE_HPP
#define NODE_HPP
class Node {
    public:
        int count;

        Node(int initial);

        void increment();
        void decrement();
};
#endif