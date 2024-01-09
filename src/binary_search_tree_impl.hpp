// BST default constructor
template <typename T> 
BST<T>::BST()         
    : root(nullptr)   
{}                    

//  initializer list constructor 
template <typename T>
BST<T>::BST(std::initializer_list<T> init) :      
    root(nullptr)                             
{                                             
    for (const auto& elem : init)
    {
      // calls insert function for every elem
      //to insert theme in rightplase
      this->insert(elem);                   
    }                                         
}                                             

// destructor
template <typename T>
BST<T>::~BST()          
{                       
    clear(root);        
} 

// Node default constructor
template <typename T>
BST<T>::Node::Node() :  
    left(nullptr),     
    right(nullptr),     
    val(0)              
{}                      

// Node parameterized constructor
template <typename T>
BST<T>::Node::Node(T val1, Node* left1, Node* right1) : 
    left(left1),                                       
    right(right1),                                      
    val(val1)                                           
{}


template <class T>                                  
BST<T>::BST(const BST& other) : root(nullptr)  // copy  constructor
{
   
    root = copy(other.root);  // calls copy recursive function for deep copying
}

//-------------------------_copy_---------------------------//
template <class T>
typename BST<T>::Node *BST<T>::copy(const Node *srcNode)  // Private helper function for copying the contents of a Binary Search Tree
{
   
    if (srcNode == nullptr) {   // Check if the source BST node is empty (base case for recursion)
      return nullptr; // If the source BST is empty, 
    }

    Node *newNode = new Node(srcNode->val, nullptr, nullptr);  // Create a new node to store the copied values from the source node

   
    newNode->left = copy(srcNode->left);  // Recursively copy the left subtree of the source node
    
    newNode->right = copy(srcNode->right); // Recursively copy the right subtree of the source node
   
    return newNode;  // Return the pointer to the newly created node with copied values
}

//----------------_clear_---------------------//

template <typename T>
void BST<T>::clear() // Public function to clear the entire Binary Search Tree
{
    clear(root); // call of Private recursive helper function
}

template <typename T>
void BST<T>::clear(Node* node) // Private helper function for clearing the contents of a Binary Search Tree
{
    if (node != nullptr)
    {
      clear(node->left); // Recursively call of left subtrees
      clear(node->right); // Recursively call of right subtrees

      delete node; // Delete the current node in posorder
    }

    root = nullptr; // After clearing all nodes, set the root to nullptr
}


//-------------------_insert_--------------------//
template <typename T>
void BST<T>::insert(const T& val1) // Public function to insert a value in right plase into the Binary Search Tree
{
    if (val1 < 0)  // Check if the value is non-negative, as the Binary Search Tree is assumed to contain non-negative values
    {
        std::cout << "in BST/insert\nval must be >=0" << std::endl;
        exit(0);
    }

    root = insert(root, val1);  // Call the private recursive helper function to perform the insertion

}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* root, const T& val1) // Private helper function to recursively insert a value into the Binary Search Tree
{ 
    if (root == nullptr)  // If the current subtree is empty, create a new node with the given value
    {
        return new Node(val1, nullptr, nullptr);
    }

    if (val1 < root->val) //If the value is less than the current node's value, insert into the left subtree
    {
        root->left = insert(root->left, val1);
    } 
    else if (val1 > root->val)  // If the value is greater than the current node's value, insert into the right subtree
    {
        root->right = insert(root->right, val1);
    }

    return root; // Return the updated root of the current subtree
}


//-----------------------_delete_---------------------------//
template <typename T>
void BST<T>::Delete(const T& val) // public function for deleting node from BST
{
    root = Delete(val, root); // call of private recursive helper function
}

template <typename T>
typename BST<T>::Node* BST<T>::Delete(const T& val, Node* root1) // Private helper function to recursively delete a value from the Binary Search Tree
{
    if (root1 == nullptr) // If the current subtree is empty, return nullptr
    {
        return root1;
    }

    if (val < root1->val)  // If the value is less than the current node's value, delete from the left subtree
    {
        root1->left = Delete(val, root1->left);
    }
    else if (val > root1->val) // If the value is greater than the current node's value, delete from the right subtree
    {
        root1->right = Delete(val, root1->right);
    } else  // Node with the value to be deleted found
    {
        if (root1->left == nullptr) // Case 1: Node has no left child
        {
            Node* tmp = root1->right;       // create temprary Node to save right child
            delete root1;                   // deklete target node 
            return tmp;                     // Return the right child to be connected with the parent of the deleted node
        } 
        else if (root1->right == nullptr) // Case 2: Node has no right child
        {
            Node *tmp = root1->left;        // create temprary Node to save lrft child
            delete root1;                   // deklete target node 
            return tmp;                     // Return the left child to be connected with the parent of the deleted node
        } else { // Case 3: Node has both left and right children                                           
            Node* tmp = find_min(root1->right);                 // Find the minimum value in the right subtree
            root1->val = tmp->val;                              // Copy the minimum value to the current node
            root1->right = Delete(root1->val, root1->right);    // Delete the node with the minimum value from the right subtree 
        }
    }

    return root1; // Return the updated root of the current subtree

    /* 
    Case 3 Explanation:
    * If the node to be deleted has both left and right children, we choose the
    * minimum value from the right subtree to replace the current node. This is
    * done to maintain the ordering property of the Binary Search Tree.
    * 1. Find the minimum value in the right subtree.
    * 2. Copy the minimum value to the current node.
    * 3. Recursively delete the node with the minimum value from the right subtree.
    */
}
//-------------------------_contains_-------------------------//
template <typename T>
bool BST<T>::contains(const T& val) // Public function to search for a value in the Binary Search Tree
{
    return search(root, val); // call of private recursive helper function
}


//----------------------_search_--------------------------//
template <typename T>
bool BST<T>::search(const T& val) // Public function to search for a value in the Binary Search Tree
{
    return search(root, val); // call of private recursive helper function
}

template <typename T>
bool BST<T>::search(Node* root1, const T& val) // Private helper function to recursively search for a value in the Binary Search Tree
{
    if (root1 == nullptr) // If the current subtree is empty which means the value is not found
    {
        return false;
    }

    if (root1->val == val) // If the current node's value matches the target value, the value is found
    {
        return true;
    }

    if (root1->val < val) // If the target value is greater than the current node's value, search in the right subtree
    {
        return search(root1->right, val);
    }

    return search(root1->left, val); // If the target value is less than the current node's value, search in the left subtree
}


//---------------------_inorder_-------------------------//
template <typename T>
void BST<T>::inorder()  // Public function to perform an inorder traversal node printing of the Binary Search Tree
{
    inorder(root);          // call of private recursive halper function
    std::cout << std::endl; // for new line after printing
}

template <typename T>
void BST<T>::inorder(Node* root1) // Private helper function to perform an inorder traversal recursively
{
    if (!root1) // If the current subtree is empty return
    {
        return;
    }
    inorder(root1->left);           // Traverse the left subtree
    std::cout << root1->val << " "; // printing the current val
    inorder(root1->right);          // Traverse the right subtree
}


//---------------------_pre_order_-------------------------//
template <typename T>
void BST<T>::pre_order()    // Public function to perform a pre-order traversal value printing of the Binary Search Tree
{
    pre_order(root);        // call of private recursive halper function
    std::cout << std::endl; // for new line after printing
}

template <typename T>
void BST<T>::pre_order(Node* root1)  // Private helper function to perform a pre-order traversal recursively
{
    if (!root1) // If the current subtree is empty return
    {
        return;
    }
    std::cout << root1->val << " "; // printing the current val
    pre_order(root1->left);         // Traverse the left subtree
    pre_order(root1->right);        // Traverse the right subtree
}


//-----------------------_post_order_---------------------------//
template <typename T>
void BST<T>::post_order()    // Public function to perform a post-order traversal value printing of the Binary Search Tree
{
    post_order(root);        // call of private recursive halper function
    std::cout << std::endl;  // for new line after printing
}

template <typename T>
void BST<T>::post_order(Node* root1)    // Private helper function to perform a post-order traversal recursively
{
    if (!root1) { // If the current subtree is empty return
        return;
    }
    post_order(root1->left);        // Traverse the left subtree
    post_order(root1->right);       // Traverse the right subtree
    std::cout << root1->val << " "; // printing the current val
}


//--------------------_find_Min_--------------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::find_min()  // Public function to find the node with the minimum value in the Binary Search Tree
{
    return find_min(root); // call of private iterative helper function
}

template <typename T>
typename BST<T>::Node* BST<T>::find_min(Node* root1) // Private helper function to find the node with the minimum value iterative
{
    if (root == nullptr) // If the root of tree is empty, print an error message and exit
    {
        std::cout << "\nfor find_min\nnullptr" << std::endl;
        exit(0);
    }

    while (root1->left != nullptr) // Iterative Traverse the left subtree until the leftmost leaf is reached
    {
        root1 = root1->left;
    }

    return root1; // Return the node with the minimum value
}


//-------------------------_find_max_-----------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::find_max() // Public function to find the node with the maximum value in the Binary Search Tree
{
    return find_max(root); // call of the private iterative helper function
}

template <typename T>
typename BST<T>::Node* BST<T>::find_max(Node* root1) // Private helper function to find the node with the maximum value iteratively
{
    if (root == nullptr) // If the root of tree is empty, print an error message and exit
    {
        std::cout << "\nfor find_max\nnullptr" << std::endl;
        exit(0);
    }


    while (root1->right != nullptr) // Iterative traverse the right subtree until the rightmost leaf is reached
    {
        root1 = root1->right;
    }

    return root1; // Return the node with the maximum value
} 

//-------------------------_height_---------------------------//
template <typename T>
int BST<T>::height() // Public function to calculate the height of the Binary Search Tree
{
    return height(root); // call of recursive helper function
}

template <typename T>
int BST<T>::height(Node* root1) // Private helper function to calculate the height of the Binary Search Tree recursively
{
    if (root1 == nullptr)  // If the current subtree is empty, it reached bottom leaf and return -1
    {
        return -1;
    }
    else
    {
        int leftH = height(root1->left);     // Calculate the height of the left subtree
        int rightH = height(root1->right);   // Calculate the height of the left subtree

        return std::max(leftH, rightH) + 1;  // Return the maximum height of the left and right subtrees, plus 1
    }
}


//-------------------------_size_-----------------------------//
template <typename T>
int BST<T>::size() const // Public function to get the size (number of nodes) of the Binary Search Tree
{
    return size(root); // call of private recursive helper function
}

template <typename T>
int BST<T>::size(Node* root1) const // Public function to get the size (number of nodes) of the Binary Search Tree
{
    if (root1 == nullptr) // If the current subtree reached the last leaf, its size is 0
    {
        return 0;
    }

    int leftSize = size(root1->left);      // Calculate the height of the left subtree
    int rightSize = size(root1->right);    // Calculate the height of the left subtree

    return leftSize + rightSize + 1;   // Return the total size of the current subtree, which is the sum of sizes of left and right subtrees, +1 (for the current node)
    
}


//--------------------------_successor_-----------------------// 
template <typename T>
typename BST<T>::Node* BST<T>::successor(const T& val) // Public function to find the successor of a node with the given value in the Binary Search Tree
{
    /*
    * Successor of a node in a Binary Search Tree (BST) is defined as
    * the node with the smallest value greater than the value of the given
    * node.
    */

    Node* tar = search_node(root, val);  // Search for the node with the given value in the BST

    if (tar == nullptr)  // If the node with the given value is not found, return nullptr
    {
        return nullptr;
    }

    if (tar->right != nullptr)  // If the node has a right subtree
    {
        return find_min(tar->right); // find and return the minimum value in that subtree
    }

    /*
    * ancestors is any other node on the path from the node to the root.
    */

    // If the node doesn't have a right subtree, find the successor using ancestors
    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != tar) // Traverse the tree to find the ancestor node whose left child is also an ancestor of the target node
    {
        if (val < ancestor->val) // If the value of the target node is less than the current ancestor's value,
        {
            successor = ancestor; // update the successor
            ancestor = ancestor->left; // move to the left child
        }
        else // If the value of the target node is greater thanthe current anssestor's value
        {
            ancestor = ancestor->right; // move to the right child

        }
    }

    return successor; // Return the successor node
}


//-------------------------_predecessor_----------------------//
template <typename T>
typename BST<T>::Node* BST<T>::predecessor(const T& val)
{

    /*
    * Predecessor of a node in a Binary Search Tree (BST) is defined as
    * the node with the largest value smaller than the value of the given node.
    */

    Node* tar = search_node(root, val); // Search for the node with the given value in the BST

    if(tar == nullptr)  // If the node with the given value is not found, return nullptr
    {
        return nullptr;
    }

    if(tar->left != nullptr) // If the node has a left subtree
    {
        return find_max(tar->left); // find the maximum value in that subtree
    }

    /*
    * ancestors is any other node on the path from the node to the root.
    */

    // If the node doesn't have a left subtree, find the predecessor using ancestors
    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != tar)  // Traverse the tree to find the ancestor node whose right child is also an ancestor of the target node
    {
        if (val < ancestor->val)  // If the value of the target node is less than the current ancestor's value
        {
            ancestor = ancestor->left; // move to the left child
        }
        else // If the value of the target node is greater than the current ancestor's value
        {
            predecessor = ancestor; // update the predecessor
            ancestor = ancestor->right; // move to the right child
        }
    }

    return predecessor;
}


//-------------------------_is_valid_bst_---------------------//
template <typename T>
bool BST<T>::is_valid_bst()  // Public function to check if the Binary Search Tree (BST) is valid
{
    return is_valid_bst(root,  std::numeric_limits<T>::min(), std::numeric_limits<T>::max()); // Calls the private helper function with the root node and the minimum and maximum limits for values
}

template <typename T>
bool BST<T>::is_valid_bst(const Node* node, const T& min_val, const T& max_val) const // Private helper function to recursively check if the Binary Search Tree (BST) is valid
{
    if (node == nullptr) // If the node is null, it is a valid BST (empty tree is valid tree)
    {
        return true;
    }

    if (node->val <= min_val || node->val >= max_val) // // If the current node's value is outside the valid range, it is not a valid BST
    {
        return false;
    }

    // Recursively check of left and right subtrees
    return is_valid_bst(node->left, min_val, node->val) &&  // The left subtree must be a valid BST with an updated maximum value (max_val becomes the current node's value).
            is_valid_bst(node->right, node->val, max_val);  //The right subtree must be a valid BST with an updated minimum value (min_val becomes the current node's value).
}


//-----------------------------_level_order_------------------------//
template <typename T>
void BST<T>::level_order() const // public function to print BST in level order
{
    std::queue<Node *> nodes; // Create a queue to perform level-order traversal

    nodes.push(root); // Start from the root node

    while (!nodes.empty()) // Continue traversal until all nodes are processed
    {
        Node* node = nodes.front(); // Dequeue the front node

        if (node->left) // Enqueue left child if it exists
        {
            nodes.push(node->left);
        }

        if (node->right) // Enqueue right child if it exists
        {
            nodes.push(node->right);
        }

        std::cout << node->val << ' '; // Print the value of the current node

        nodes.pop();// Dequeue the processed node
    }
}


//-----------------------------_print_tree_------------------------//
// template <typename T>
// void BST<T>::print_tree() const
// {
//     std::queue<Node*> nodes;
    
//     nodes.push(root);

//     int num = 1;
//     int po = 1;

//     while (!nodes.empty())
//     {
//         Node* node = nodes.front();
//         if (node->left)
//         {
//             nodes.push(node->left);
//         }
//         else 
//         {
//             nodes.push(nullptr);
//         }

//         if (node->right)
//         {
//             nodes.push(node->right);
//         }
//         else 
//         {
//             nodes.push(nullptr);
//         }

//         if(nodes.front() != nullptr)
//         {
//             std::cout << node->val << ' ';
//             nodes.pop();
//         }
//         else 
//         {
//             nodes.pop();
//             std::cout << "  " << std::endl;
//         }

        
//         num += 1;
//         po += 1;

//         if(std::pow(num, 1.0 / po) == 0)
//         {
//             std::cout << std::endl;
//         }
//     }
// }





//------------------------_serialize_-------------------------//
template <typename T>
std::vector<T> BST<T>::serialize() // Public function to serialize the Binary Search Tree (BST)
{  
    std::vector<T> vec; // create a vector to save values
    serialize(root, vec); // Call the private ecursive helper function to perform the serialization starting from the root

    return vec; // Return the serialized vector
}

template <typename T>
void BST<T>::serialize(Node* root1, std::vector<T>& vec) // Private helper function to perform the recursive serialization of the BST
{

    if (!root1) // If the current node is null, return
    {
        return;
    }

    serialize(root1->left, vec); // Recursively serialize the left subtree
    vec.emplace_back(root1->val); // Append the value of the current node to the vector in in-order order
    serialize(root1->right, vec); // Recursively serialize the right subtree
}


//--------------------------_range_query_---------------------//
template <typename T>
void BST<T>::range_query(int start, int end) // Public function to perform a range query on the Binary Search Tree (BST)
{
    if (start > end) // Ensure that the start value is not greater than the end value
    {
        return; // Invalid range, return without processing
    }

    range_query(start, end, root); // Call the private recursive helper function to perform the range query starting from the root
}

template <typename T>
void BST<T>::range_query(int start, int end, Node* root1) // Private helper function to perform the recursive range query on the BST
{
    if (!root1) // If the current node is null, return
    {
        return;
    }

    range_query(start, end, root1->left);  // Recursively perform the range query on the left subtree

    if (root1->val >= start && root1->val < end)  // Check if the value of the current node is within the specified range
    {
        std::cout << root1->val << " "; // Print the value of the current node
    }
    else if (root1->val == end) // Check if the value of the current node is equal to the end value
    {
        std::cout << std::endl;  // Print a newline and return, as we reached the end of the range
        return;
    }

    range_query(start, end, root1->right);  // Recursively perform the range query on the right subtree

    // to ensure that a newline is printed when the end value of the range is encountered during the traversal
    // if (root1->val == end) // Check if the value of the current node is equal to the end value
    // {
    //     std::cout << std::endl; // Print a newline and return, as we reached the end of the range 
    //     return; 
    // }
}


//------------------------_kth_smallest_--------------------------//
template <typename T>
const T& BST<T>::kth_smallest(int k)  // Public function to find the kth smallest element in the Binary Search Tree (BST)
{
    return kth_smallest(root, k)->val;   // Call the private helper function to perform the search starting from the root
}

template <typename T>
typename BST<T>::Node* BST<T>::kth_smallest(Node* root, int& k) // Private helper function to recursively find the kth smallest element in the BST
{
    if (root == nullptr) // If the current node is null, return nullptr
    {
        return nullptr;
    }

    Node* left = kth_smallest(root->left, k); // Recursively search the left subtree

    if (left != nullptr)   // If the kth smallest element is found in the left subtree, return it
    {
        return left;
    }

    k--; // Decrease the value of k after visiting the left subtree

    if (k == 0) // Check if the current node is the kth smallest element
    {
        return root;
    }

    return kth_smallest(root->right, k); // Recursively search the right subtree
}


//---------------------------_kth_largest_-----------------------//
template <class T>
const T& BST<T>::kth_largest(int k) // Public function to find the kth largest element in the Binary Search Tree (BST)
{
    Node* res = kth_largest_node(k); // Call the private helper function to get the kth largest node

    if (res != nullptr) // If a valid node is found, return its value
    {
        return res->val;
    }
    else // throw an exception
    if (res != nullptr)
    {
        throw std::out_of_range("Invalid value of k for kth_largest.");
    }
}

template <class T>
typename BST<T>::Node* BST<T>::kth_largest_node(int k) // Private  helper function to find the kth largest node in the BST
{
    Node* curr = root; // Initialize current node with root
    Node* Klargest = nullptr; // pointer to the kth largest node

    int count = 0; // Initialize count to keep track of the number of nodes visited

    /*
    * Morris Traversal is a tree traversal algorithm 
    * that allows the traversal of binary trees without 
    * using recursion or an explicit stack. The key idea 
    * behind Morris Traversal is to modify the structure 
    * of the tree while traversing, without using additional
    * data structures like stacks or queues.
    */

    while (curr != nullptr)   // Traverse the BST using Morris Traversal to find the kth largest node
    {
        if (curr->right == nullptr) // If the right child of the current node is null, move to the left child
        {
            if (++count == k)  // Check if the current node is the kth largest node and increase count by 1
            {
              Klargest = curr; // asign Klargest with current
            }

            curr = curr->left; // Move to the left child
        } 
        else // If the right child of the current node is NOT null
        {
            Node* succ = curr->right;

            while (succ->left != nullptr && succ->left != curr) // Traverse to the leftmost node in the right subtree to find the in-order successor
            {    
                succ = succ->left;
            }

            if (succ->left == nullptr)  // If the in-order successor's left child is null, update it to point to the current node
            {
                succ->left = curr;

                curr = curr->right;  // Move to the right child for further exploration in the right subtree
            } 
            else // If the in-order successor's left child is NOT null, reset it to null
            {
                succ->left = nullptr;  // This marks the end of exploration in the right subtree, and we backtrack to the left subtree

                if (++count == k) // Check if the current node is the kth largest node and increase count by 1
                {
                    Klargest = curr;
                }
                curr = curr->left;  // Move to the left child for further exploration in the left subtree
            }
        }
    }

    return Klargest; // Return the pointer to the kth largest node
}


//--------------------------_update_--------------------------//
template <class T>
void BST<T>::update(const T& value, const T& new_value)
{
    Delete(value); // Delete the node with the specified value from the BST
    insert(new_value); // Insert the new value into the BST
} 


//-------------------------_get_root_------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::get_root()
{
    return root; // return the pointer to root of givven tree
}


//--------------------------_search_node_---------------------//
template <typename T>
typename BST<T>::Node* BST<T>::search_node(Node* root1, const T& val)
{
    if(root1 == nullptr) // If the current node is null, the value is not found in the tree
    {
        return nullptr;
    }

    if(root1->val == val)  // Check if the value of the current node is equal to the target value
    {
        return root1; // Return the current node as it contains the target value
    }

    if(root1->val < val)  // If the target value is greater than the value of the current node,
    {
        return search_node(root1->right, val); // search in the right subtree
    }

    // If the target value is smaller than the value of the current node
    return search_node(root1->left, val); // search in the left subtree
}
