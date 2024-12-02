#include "node.hpp"
#include <queue>
#include <vector>
#include <iostream>

// First Node is class name/namespace, second Node is name of class again because its the constructor
Node::Node(const std::string symbol, int frequency)
    : symbol(symbol), frequency(frequency) {
}

Node Node::join(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
    std::string concat_symbol = left->symbol + right->symbol;
    int combined_frequency = left->frequency + right->frequency;
   
    Node parent_node(concat_symbol, combined_frequency);
    parent_node.left = left;   // Set the left child pointer
    parent_node.right = right; // Set the right child pointer

    return parent_node;
}

bool Node::is_leaf() const {// const afterward means the instance of the class is not changed. if it was inside of the brackets it would mean you can't change the parameter.
    return (left == nullptr && right == nullptr);
}

void Node::print_tree(std::shared_ptr<Node> node, std::string& indent, bool last) const {
    if (node != nullptr) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";  // "R" for right child
            indent += "     ";    // Increase indentation for next level
        } else {
            std::cout << "L----";  // "L" for left child
            indent += "|    ";     // Increase indentation for next level
        }
        std::cout << node->symbol << " (" << node->frequency << ")" << std::endl;

        // Recursively print the left and right children
        print_tree(node->left, indent, false);
        print_tree(node->right, indent, true);
    }
}

std::shared_ptr<Node> Node::build_tree(const std::unordered_map<std::string, int> &my_histogram){
    // Define the comparison lambda for the priority queue (min-heap)
    auto compare = [](const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b) {
        return a->frequency > b->frequency; // Min-heap: smallest frequency at the top
    };

    // Priority queue to store the nodes
    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, decltype(compare)> my_pq(compare);

    // Iterate through the histogram and create a Node for each entry
    for (const auto &entry : my_histogram) {
        const std::string &symbol = entry.first; // Symbol (key)
        int frequency = entry.second;           // Frequency (value)

        // Create a new node with the symbol and frequency
        std::shared_ptr<Node> new_node = std::make_shared<Node>(symbol, frequency);

        // Add the node to the priority queue
        my_pq.push(new_node);
    }
    //debugginggggggggggggggggggggggggggggggggggggggggggggggg
    // Temporary priority queue to preserve the original queue
    // auto temp_pq = my_pq;

    // while (!temp_pq.empty()) {
    //     // Get the top node (node with the lowest frequency due to min-heap)
    //     auto node = temp_pq.top();
    //     temp_pq.pop();

    //     // Print the symbol and frequency of the node
    //     std::cout << "Symbol: " << node->symbol << ", Frequency: " << node->frequency << std::endl;
    // }
    //debugginggggggggggggggggggggggggggggggggggggggggggggggg

    // Now, build the Huffman tree
    while (my_pq.size() > 1) {  // Continue until there's only one node in the queue
        // Get the two nodes with the lowest frequency
        std::shared_ptr<Node> left = my_pq.top();  // Node with lowest frequency
        my_pq.pop();
        std::shared_ptr<Node> right = my_pq.top(); // Node with second-lowest frequency
        my_pq.pop();

        // Combine these two nodes into a parent node
        std::shared_ptr<Node> parent = std::make_shared<Node>(Node::join(left, right));

        // Add the parent node back into the priority queue
        my_pq.push(parent);
    }
    
    return my_pq.top();
}
void Node::generate_huffman_codes(std::shared_ptr<Node> node, const std::string& code, 
                                   std::unordered_map<std::string, std::string>& huffman_codes) {
    if (node == nullptr) return;

    // If the node is a leaf, store the symbol and its Huffman code
    if (node->is_leaf()) {
        huffman_codes[node->symbol] = code;
        return;
    }

    // Traverse the left child with an appended '0'
    generate_huffman_codes(node->left, code + "0", huffman_codes);

    // Traverse the right child with an appended '1'
    generate_huffman_codes(node->right, code + "1", huffman_codes);
}




// std::unordered_map<std::string, std::string> Node::symbol_table() const {
//     std::unordered_map<std::string, int> my_table; //initialize the output "my_table" with k,v pairs.
//     std::priority_queue<Node, std::vector<int>, std::greater<int>> my_priority_queue;
//     //code that works
//  }

//Make class node. 
//needs attributes of symbol, frequency, left child and right child
//right function that puts nodes together
