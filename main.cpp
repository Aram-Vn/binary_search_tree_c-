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
    
    std::cout << "****_pre_***" << std::endl;
    b.pre_order();
    std::cout << "****_in_***" << std::endl;
    b.inorder();
    std::cout << "****_post_***" << std::endl;
    b.post_order();

    if(b.search(6))
    {
        std::cout << "Yes" << std::endl;
    }

    if(b.search(8))
    {
        std::cout << "Yes" << std::endl;
    }

    if(!(b.search(7)))
    {
         std::cout << "NO" << std::endl;
    }

    if(!(b.search(-1)))
    {
         std::cout << "NO" << std::endl;
    }

    std::cout << "*******" << std::endl;

    std::cout << "Min is:  " << b.find_min() << std::endl;
    std::cout << "Max is:  " << b.find_max() << std::endl;

    b.clear();
    std::cout << "Max is:  " << b.find_max() << std::endl;
}   