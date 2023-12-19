#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <initializer_list>

template <class T>
class BST
{
public:
    struct Node
    {
        Node* left;
        Node* right;
        T val;

        ~Node();
        Node();
        Node(T val, Node* ptr, Node* ptr1);
    };

    Node* root;
public:
    ~BST();
    BST();

    void insert(const T& val1);
    void clear(Node* node);
    void inorder();
    void inorder(Node* root1);
    Node* get_root();

    Node* insert_rec(Node* node1, const T& val1);


};

#include "binary_search_tree_impl.hpp"

#endif // BINARY_SEARCH_TREE_H
