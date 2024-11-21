#include "node.hpp"

Node::Node(int initial): count(initial) {
    
}

void Node::increment () {
    count++;
}

void Node::decrement () {
    count--;
}
