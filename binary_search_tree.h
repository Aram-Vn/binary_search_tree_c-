#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits>
#include <queue>
#include <cmath>

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
    BST(const BST& other);
    BST(std::initializer_list<T> init);

public: 
    void clear(); //
    void insert(const T& val1); //
    void Delete(const T& val); //
    bool search(const T& val);//
    void inorder(); //
    void pre_order(); //
    void post_order(); //
    Node* find_min(); //
    Node* find_max(); //
    int height(); //
    Node* successor(const T& val); //
    Node* predecessor(const T& val); //
    int size() const; //
    bool is_valid_bst(); //
    
    void print_tree() const; //
    void level_order() const; 
    bool contains(const T& val); //
    std::vector<T> serialize(); //

    void range_query(int start, int end);
    Node* copy();
    T& kth_smallest(int k);
    T& kth_largest(int k);
    void update(const T& value, const T& new_value);

    Node* get_root(); //




private:
    void clear(Node* node); //
    Node* insert(Node* node1, const T& val1); //
    Node* Delete(const T& val, Node* root1); //
    bool search(Node* root1, const T& val); //
    void inorder(Node* root1); //
    void pre_order(Node* root1); //
    void post_order(Node* root1); //
    Node* find_min(Node* root1); //
    Node* find_max(Node* root1); //
    int height(Node* root1); //
    int size(Node* root1) const;
    Node* search_node(Node* root1, const T& val); //
    bool is_valid_bst(const Node* node, const T& min_val, const T& max_val) const;//
    void serialize(Node* root1, std::vector<T>& vec);
};

#include "binary_search_tree_impl.hpp"

#endif // BINARY_SEARCH_TREE_H
