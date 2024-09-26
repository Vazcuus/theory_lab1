#include <iostream>
#include "huffman_code.h"
#include "huffman_tree_node.h"
int main(int, char**)
{
    std::string symbols = "abcdefgy";
    std::vector<float> odds = {0.22, 0.18, 0.15, 0.13, 0.13, 0.09, 0.05, 0.05};
    huffman_code tree(odds);
    tree.HuffmanWork(symbols);
}
