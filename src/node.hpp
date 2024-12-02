#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <memory> // For shared pointers
#include <functional>
#include <unordered_map>

class Node {
    public:
        
        std::string symbol;                 // The string this node represents
        int frequency;                      // The frequency of the symbol(s)
        std::shared_ptr<Node> left = nullptr;         // Pointer to left child
        std::shared_ptr<Node> right = nullptr;        // Pointer to right child

        //Constructor
        Node(std::string symbol, int frequency);

        //Methods
        static Node join(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
     
        bool is_leaf() const;//different type of const, now its after. this means the object it acts on is not mutated. 

        // void dfs(const std::function<void(const Node&)>& callback) const;
        // first const means parameter "callback" cant be changed
        //the type is "function"
        //what is the type of callback? its very complicated. 
        //last const means that the node object is not changed by this method

        std::unordered_map<std::string, std::string> symbol_table() const;//node.symbol_table() called on root.

        static std::shared_ptr<Node> build_tree(const std::unordered_map<std::string, int> &my_histogram);

        // Print the tree (for debugging purposes)
        void print_tree(std::shared_ptr<Node> node, std::string& indent, bool last) const;

        static void generate_huffman_codes(std::shared_ptr<Node> node, const std::string& code, std::unordered_map<std::string, std::string>& huffman_codes);

};
#endif