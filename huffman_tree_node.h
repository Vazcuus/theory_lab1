#pragma once
#include "huffman_code.h"
#include <vector>
class huffman_node
{
    char ch;
    float odds;
    huffman_node *left, *right;
    friend class huffman_code;

    public:
        huffman_node() {};
        huffman_node(char _ch, float _odds);
};

huffman_node::huffman_node(char _ch, float _odds)
{
	left = right = NULL;
	ch = _ch;
	odds = _odds;
}