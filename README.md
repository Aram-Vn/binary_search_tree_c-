# Binary search tree

## What is a Binary Search Tree (BST)?
A Binary Search Tree is a tree data structure in which each node has at most two children, referred to as the left and right child. The key property of a BST is that the values in the left subtree of a node are less than the value of the node, and values in the right subtree are greater. This property ensures efficient searching, insertion, and deletion operations.

## Features
## Constructors and Destructors

- `BST()`: Default constructor.
- `~BST()`: Destructor.
- `BST(const BST& other)`: Copy constructor.
- `BST(std::initializer_list<T> init)`: Initializer_list constructor.

## Basic Operations

- `void clear()`: Clear the entire Binary Search Tree.
- `void insert(const T& val)`: Insert a value into the Binary Search Tree.
- `void Delete(const T& val)`: Delete a node from the Binary Search Tree.
- `bool search(const T& val)`: Search for a value in the Binary Search Tree.

## Traversal Methods

- `void inorder()`: Perform an inorder traversal and print nodes of the Binary Search Tree.
- `void pre_order()`: Perform a pre-order traversal and print values of the Binary Search Tree.
- `void post_order()`: Perform a post-order traversal and print values of the Binary Search Tree.

## Node Analysis

- `Node* find_min()`: Find the node with the minimum value in the Binary Search Tree.
- `Node* find_max()`: Find the node with the maximum value in the Binary Search Tree.
- `int height()`: Return the height of the Binary Search Tree.
- `Node* successor(const T& val)`: Find the successor of a node with the given value.
- `Node* predecessor(const T& val)`: Find the predecessor of a node with the given value.

## Size and Validation

- `int size() const`: Return the size (number of nodes) of the Binary Search Tree.
- `bool is_valid_bst()`: Check if the Binary Search Tree (BST) is valid.

## Advanced Operations

- `void level_order() const`: Print the BST in level order.
- `bool contains(const T& val)`: Search for a value in the Binary Search Tree.
- `std::vector<T> serialize()`: Serialize the Binary Search Tree (BST) into a vector in in-order order.
- `void range_query(int start, int end)`: Perform a range query on the Binary Search Tree (BST).
- `const T& kth_smallest(int k)`: Find the kth smallest element in the Binary Search Tree (BST).
- `const T& kth_largest(int k)`: Find the kth largest element in the Binary Search Tree (BST).

## Update Operation

- `void update(const T& value, const T& new_value)`: Replace a node with the given value with a new node with the new value.

## How to Use
Clone the repository:

with ssh`
   ```bash
   git clone git@github.com:Aram-Vn/binary_search_tree_cpp.git
   cd binary-search-tree
   ```
with HTTPS`       
   ```bash
   git clone https://github.com/Aram-Vn/binary_search_tree_cpp.git
   cd binary-search-tree
   ```
or with GitHub CLI
   ```bash
   git clone https://github.com/Aram-Vn/binary_search_tree_cpp.git
   cd binary-search-tree
   ```

After clonning you can add main.cpp in crs/ and use cmake to compile.

## Build instruction
1. Generate the cmake build files first by executing the following command at the root directory:
```
cmake ./ -B build/
```
You will see a `build` folder in the root directory which will contain cmake's generation files.

2. Compile and build the cmake project:
```
cmake --build build/
```

3. Run the executable:
```
build/BinarySearchTree
```

## Or you can just move `binary_search_tree_impl.hpp` and `binary_search_tree.h` to your working directory 

1.Include the "binary_search_tree.h" file in your C++ project.
   ```cpp
    #include binary_search_tree.h
   ```
2.Use the BST class and its methods in your code.