#include "files.hpp" //only include header files, compilation errors if its not just header files.
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "node.hpp"
#include "histograms.hpp"

int main(int argc, char *argv[]) {//suspect: passing argv[1] as C string causes ≡°ƒ2O, implicit conversion. This was not the problem
    if (argc == 2) {

        std::string path = argv[1]; // This is passing by value. alternative path(argv[1])
        // std::string source = read_file(argv[1]);//passed argv[1] by value/refrence if use other line
        std::string source = read_file(path);// We now knows its treating path as a C++
       //printf("%s", source.c_str()); //output of readfile is string. It's being copied into the var source, could be big.
       //printf("%s\n%zu\n", source.c_str(), source.size());
        auto my_hist = histogram(source);
        // Build the Huffman tree
        std::shared_ptr<Node> huffman_tree_root = Node::build_tree(my_hist);

        // //deugging: Print the tree structure to verify it
        // std::string indent = "";
        // huffman_tree_root->print_tree(huffmanTreeRoot, indent, true);
        // //debugging

        std::unordered_map<std::string, std::string> huffman_codes;
        Node::generate_huffman_codes(huffman_tree_root, "", huffman_codes);

        //debugging to check huffman codes start
        std::cout << "\nHuffman Codes:\n";
        for (const auto& entry : huffman_codes) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
        //debugging to check huffman codes end
    } 
    else{
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
    }
    // std::unordered_map<std::string, int> histogram;
    //std::string path = argv[1]; // alternative path(argv[1])

    // std::string source = read_file(argv[1]);
    // passed argv[1] by value/refrence if use other line
    // We now knows its treating path as a C++
    //std::string source = read_file(path);

    // output of readfile is strong. It's being copied into the var source, could be big.
    //std::printf("%s", source.c_str());

    return 0;
    }

