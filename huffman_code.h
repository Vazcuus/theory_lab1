#pragma once
#include "huffman_tree_node.h"
#include <string>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>

class huffman_code
{
    private:
        huffman_node *root;
        std::map<char,std::string> codes;
        std::vector<float> odds;
        float length = 0;
        float entropy = 0;
        float surplus = 0;
    public:
        huffman_code (){};
        huffman_code(std::vector<float> _odds)
        {
            odds = _odds;
        }
        void HuffmanWork(std::string ch);
        void SaveCodes(huffman_node *root, std::string str)
        {
            if (!root) return;
            
            if (root->ch != '%')
            {
                codes[root->ch] = str;
            }
            SaveCodes(root->left, str + "0");
            SaveCodes(root->right, str + "1");
        }
        struct Comparator
        {
            bool operator()(huffman_node *left, huffman_node *right)
            {
                return (left->odds > right->odds);
            }
        };

        void PrintCodes(std::map<char, std::string> codes)
        {
            for (const auto& pair : codes)
            {
                std::cout << pair.first << ": " << pair.second;
                std::cout << std::endl;

            }
        }
        float PrintLength()
        {
            int i =0;
            for (const auto& pair : codes)
            {
                length += odds[i++]*pair.second.size();
            }
            std::cout << "Length: " <<length << std::endl;
            return length;
        }
        float PrintEntropy()
        {
            int i =0;
            for (auto i = 0; i < odds.size(); i++)
            {
                entropy += odds[i]*log(odds[i])/log(odds.size());
            }
            std::cout << "Entropy: " << (float)-entropy << std::endl;
            return -entropy;
        }
        float PrintSurplus()
        {
            std::cout << "Surplus: " << float(1 + entropy) << std::endl;
            return 1 + entropy;
        }
};

void huffman_code::HuffmanWork(std::string ch)
{
    huffman_node *left, *right, *top;

    std::priority_queue<huffman_node*, std::vector<huffman_node*>, Comparator> result;

    for (int i = 0; i < ch.size(); i++)
    {
        huffman_node* temp = new huffman_node(ch[i], odds[i]);
        result.push(temp);
    }

    while (result.size() != 1)
    {
        left = result.top();
        result.pop();
        right = result.top();
        result.pop();

        top = new huffman_node('%', left->odds + right->odds);
        top->left = left;
        top->right = right;
        result.push(top);

    }
    root = result.top();
    SaveCodes(root, "");
    PrintCodes(codes);
    PrintLength();
    PrintEntropy();
    PrintSurplus();
    
}