#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <initializer_list>

template <class T>
class BST
{
public:



public:
    struct Node
    {
        Node* left;
        Node* right;
        T val;
    };

    Node* root;
};

#include "binary_search_tree_impl.hpp"

#endif // BINARY_SEARCH_TREE_H
