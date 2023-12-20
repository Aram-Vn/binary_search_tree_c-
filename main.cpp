#include <iostream>
#include "binary_search_tree.h"

int main () {

    BST<int> b;

    b.insert(60);
    b.insert(50);
    b.insert(70);
    b.insert(40);
    b.insert(55);
    b.insert(65);
    b.insert(80);
    b.insert(30);
    b.insert(45);
    b.insert(53);
    b.insert(58);
    b.insert(63);
    b.insert(68);
    b.insert(75);
    b.insert(90);
    b.insert(20); 
    b.insert(35);
    b.insert(42);

    std::cout << b.height() << std::endl; 
    

    // std::cout << "****_pre_***" << std::endl;
    // b.pre_order();
    // std::cout << "****_in_***" << std::endl;
    // b.inorder();
    // std::cout << "****_post_***" << std::endl;
    // b.post_order();

    // b.Delete(40);


    // std::cout << "max:  "<< b.find_max()->val << std::endl;
    // std::cout << "MIN:  "<< b.find_min()->val << std::endl;

    // std::cout << b.successor(20)->val << std::endl;
    // std::cout << b.successor(50)->val << std::endl;

}   