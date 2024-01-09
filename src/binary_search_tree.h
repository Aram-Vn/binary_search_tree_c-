#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

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
    ~BST();                             //
    BST();                              //
    BST(const BST& other);              //
    BST(std::initializer_list<T> init); //

public:
    void clear();                         // clear the entire Binary Search Tree
    void insert(const T& val1);           // insert a value in right plase into the Binary Search Tree
    void Delete(const T& val);            // deleting node from BST
    bool search(const T& val);            // search for a value in the Binary Search Tree
    void inorder();                       // perform an inorder traversal node printing of the Binary Search Tree
    void pre_order();                     // perform a pre-order traversal value printing of the Binary Search Tree
    void post_order();                    // perform a post-order traversal value printing of the Binary Search Tree
    Node* find_min();                     // find the node with the minimum value in the Binary Search Tree
    Node* find_max();                     // find the node with the maximum value in the Binary Search Tree
    int height();                         // returns the height of the Binary Search Tree
    Node* successor(const T& val);        // find the successor of a node with the given value in the Binary Search Tree
    Node* predecessor(const T& val);      // find the predecessor of a node with the given value in the Binary Search Tree
    int size() const;                     // returns the size (number of nodes) of the Binary Search Tree
    bool is_valid_bst();                  // checks if the Binary Search Tree (BST) is vali
    void level_order() const;             // prints BST in level order
    bool contains(const T& val);          // search for a value in the Binary Search Tree
    std::vector<T> serialize();           // serializes the Binary Search Tree (BST) by inserting its nodes in vector in in-order order
    void range_query(int start, int end); // perform a range query(prints elements in specific range) on the Binary Search Tree (BST)
    const T& kth_smallest(int k);         // find the kth smallest element in the Binary Search Tree (BST)
    const T& kth_largest(int k);          // find the kth largest element in the Binary Search Tree (BST)
    void update(const T& value, const T& new_value); // replased node with value with new_node

private: // helper functions
    Node* get_root();
    void clear(Node* node);
    Node* copy(const Node* srcNode);
    Node* insert(Node* root, const T& val1);
    Node* Delete(const T& val, Node* root1);
    bool search(Node* root1, const T& val);
    void inorder(Node* root1);
    void pre_order(Node* root1);
    void post_order(Node* root1);
    Node* find_min(Node* root1);
    Node* find_max(Node* root1);
    int height(Node* root1);
    int size(Node* root1) const;
    Node* search_node(Node* root1, const T& val);
    bool is_valid_bst(const Node* node, const T& min_val, const T& max_val) const;
    void serialize(Node* root1, std::vector<T>& vec);
    void range_query(int start, int end, Node* root1);
    Node* kth_smallest(Node* root, int& k);
    Node* kth_largest_node(int k);
};

#include "binary_search_tree_impl.hpp"

#endif // BINARY_SEARCH_TREE_H
