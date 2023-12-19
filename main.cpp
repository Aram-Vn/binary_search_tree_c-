#include <iostream>
#include "binary_search_tree.h"

int main () {

 BST<int> b;

b.insert(1);
b.insert(2);
b.insert(3);
b.insert(5);
b.insert(2);

b.inorder();

    // std::cout << "**********" << std::endl;

    // BST<int>::Node* root = nullptr;
    // BST<int> b1;

    // root = b1.insert_rec(root, 0);

    // b1.insert_rec(root, 1);
    // b1.insert_rec(root, 2);
    // b1.insert_rec(root, 3);
    // b1.insert_rec(root, 5);
    // b1.insert_rec(root, 99);

    // b1.inorder(root);
    //     std::cout << std::endl;
}   