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

        ~Node() = default;
        Node();
        Node(T val, Node* ptr, Node* ptr1);
    };

    Node* root;
public:
    ~BST();
    BST();

public: 
    void clear(); //
    void insert(const T& val1); //
    
    void Delete(const T& val);
    
    bool search(const T& val);//
    void inorder(); //
    void pre_order(); //
    void post_order(); //
    const T& find_min(); //
    const T& find_max(); //

    Node* get_root(); //


private:
    void clear(Node* node); //
    Node* insert(Node* node1, const T& val1); //
    bool search(Node* root1, const T& val); //
    void inorder(Node* root1); //
    void pre_order(Node* root1); //
    void post_order(Node* root1); //
    const T& find_min(Node* root1); //
    const T& find_max(Node* root1); //
    


};

#include "binary_search_tree_impl.hpp"

#endif // BINARY_SEARCH_TREE_H
