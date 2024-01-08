#include <iostream>
#include "binary_search_tree.h"

int main () {

    BST<int> b = {60, 50, 70, 40, 55, 65, 80, 30, 45, 53, 58, 63, 68, 75, 90, 20, 35, 42};

    std::cout << b.kth_smallest(2) << std::endl; 

    // b.range_query(40, 65);
    // b.range_query(70, 90);

    // // std::cout << b.kth_largest(5) << std::endl;
    // //std::cout << b.height() << std::endl; 
    
    // std::cout << "****_pre_***" << std::endl;
    // b.pre_order();
    std::cout << "****_in_***" << std::endl;
    b.inorder();

    // b.update(20, 999);

    // std::cout << "****_in_***" << std::endl;
    // b.inorder();
    // // std::cout << "****_post_***" << std::endl;
    // // b.post_order();

    // // b.Delete(40);

    // if(b.is_valid_bst())
    // {
    //     std::cout << "YES" << std::endl;
    // }

    // b.range_query(40, 75);


    // std::cout << "max:  "<< b.find_max()->val << std::endl;
    // std::cout << "MIN:  "<< b.find_min()->val << std::endl;

    // std::cout << b.successor(50)->val << std::endl;
    // std::cout << b.predecessor(53)->val << std::endl;

}   