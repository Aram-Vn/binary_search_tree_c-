template <typename T>
BST<T>::BST() :
    root(nullptr)
{}

template <typename T>
BST<T>::BST(std::initializer_list<T> init) : 
    root(nullptr)
{
    for (const auto& elem : init) {
        this->insert(elem);
    }
}

template <typename T>
BST<T>::~BST()
{
    clear(root);
}

template <typename T>
BST<T>::Node::Node() : 
    left(nullptr),
    right(nullptr),
    val(0)
{}

template <typename T>
BST<T>::Node::Node(T val1, Node* left1, Node* right1) :
    left(left1),
    right(right1),
    val(val1)
{}  


//----------------_clear_---------------------//
template <typename T>
void BST<T>::clear()
{
    clear(root);
}

template <typename T>
void BST<T>::clear(Node* node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);

        delete node;
    }

    root = nullptr;
}


//-------------------_insert_--------------------//
template <typename T>
void BST<T>::insert(const T& val1) 
{
    if (val1 < 0)
    {
        std::cout << "in BST/insert\nval must be >=0" << std::endl;
        exit(0);
    }

    root = insert(root, val1);

}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* node1, const T& val1)
{
    if (node1 == nullptr)
    {
        return new Node(val1, nullptr, nullptr);
    }

    if (val1 < node1->val) 
    {
        node1->left = insert(node1->left, val1);
    } 
    else if (val1 > node1->val) 
    {
        node1->right = insert(node1->right, val1);
    }

    return node1;
}


//-----------------------_delete_---------------------------//
template <typename T>
void BST<T>::Delete(const T& val)
{
    root = Delete(val, root);
}

template <typename T>
typename BST<T>::Node* BST<T>::Delete(const T& val, Node* root1)
{
    if (root1 == nullptr)
    {
        return root1;
    }

    if (val < root1->val)
    {
        root1->left = Delete(val, root1->left);
    }
    else if (val > root1->val)
    {
        root1->right = Delete(val, root1->right);
    }
    else
    {
        if (root1->left == nullptr)
        {
            Node* tmp = root1->right;
            delete root1;
            return tmp;
        } 
        else if (root1->right == nullptr)
        {
            Node* tmp = root1->left;
            delete root1;
            return tmp;
        }
        else
        {
            Node* tmp = find_min(root1->right);
            root1->val = tmp->val;
            root1->right = Delete(root1->val, root1->right);
        }
    }

    return root1;

}

//----------------------_search_--------------------------//
template <typename T>
bool BST<T>::search(const T& val)
{
    return search(root, val);
}

template <typename T>
bool BST<T>::search(Node* root1, const T& val)
{
    if (root1 == nullptr)
    {
        return false;
    }

    if (root1->val == val)
    {
        return true;
    }

    if (root1->val < val)
    {
        return search(root1->right, val);
    }

    return search(root1->left, val);
}


//---------------------_inorder_-------------------------//
template <typename T>
void BST<T>::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::inorder(Node* root1)
{
    if (!root1) {
        return;
    }
    inorder(root1->left);
    std::cout << root1->val << " ";
    inorder(root1->right);
}


//---------------------_pre_order_-------------------------//
template <typename T>
void BST<T>::pre_order()
{
    pre_order(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::pre_order(Node* root1)
{
    if (!root1) {
        return;
    }
    std::cout << root1->val << " ";
    pre_order(root1->left);
    pre_order(root1->right);
}


//-----------------------_post_order_---------------------------//
template <typename T>
void BST<T>::post_order()
{
    post_order(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::post_order(Node* root1)
{
    if (!root1) {
        return;
    }
    post_order(root1->left);
    post_order(root1->right);
    std::cout << root1->val << " ";
}


//--------------------_find_Min_--------------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::find_min()
{
    return find_min(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::find_min(Node* root1)
{
    if (root == nullptr)
    {
        std::cout << "\nfor find_min\nnullptr" << std::endl;
        exit(0);
    }

    while (root1->left != nullptr)
    {
        root1 = root1->left;
    }

    return root1;
}


//-------------------------_find_max_-----------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::find_max()
{
    return find_max(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::find_max(Node* root1)
{
    if (root == nullptr)
    {
        std::cout << "\nfor find_max\nnullptr" << std::endl;
        exit(0);
    }


    while (root1->right != nullptr)
    {
        root1 = root1->right;
    }

    return root1;
}

//-------------------------_height_---------------------------//
template <typename T>
int BST<T>::height()
{
    return height(root);
}

template <typename T>
int BST<T>::height(Node* root1)
{
    if (root1 == nullptr)
    {
        return -1;
    }
    else
    {
        int leftH = height(root1->left);
        int rightH = height(root1->right);

        // std::cout << "root->val   " << root1->val << std::endl;
        // std::cout << "leftH   " << leftH << std::endl;
        // std::cout << "rightH   " << rightH << std::endl;

        return std::max(leftH, rightH) + 1;
    }
}


//-------------------------_size_-----------------------------//
template <typename T>
int BST<T>::size() const
{
    return size(root);
}

template <typename T>
int BST<T>::size(Node* root1) const
{
    if (root1 == nullptr)
    {
        return 0;
    }

    int leftSize = size(root1->left);
    int rightSize = size(root1->right);

        std::cout << "**************\nroot->val   " << root1->val << std::endl;
        std::cout << "leftSize   " << leftSize << std::endl;
        std::cout << "rightSize   " << rightSize << std::endl;

    return leftSize + rightSize + 1;
}


//--------------------------_successor_-----------------------//
template <typename T>
typename BST<T>::Node* BST<T>::successor(const T& val)
{
    Node* tar = search_node(root, val);

    if (tar == nullptr)
    {
        return nullptr;
    }

    if (tar->right != nullptr)
    {
        return find_min(tar->right);
    }

    Node* successor = nullptr;
    Node* ancestor = root;

    while (ancestor != tar)
    {
        if (val < ancestor->val)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }

    return successor;
}


//-------------------------_predecessor_----------------------//
template <typename T>
typename BST<T>::Node* BST<T>::predecessor(const T& val)
{
    Node* tar = search_node(root, val);

    if(tar == nullptr)
    {
        return nullptr;
    }

    if(tar->left != nullptr)
    {
        return find_max(tar->left);
    }

    Node* predecessor = nullptr;
    Node* ancestor = root;

    while (ancestor != tar)
    {
        if (val < ancestor->val)
        {
            ancestor = ancestor->left;
        }
        else
        {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
    }

    return predecessor;
}


//-------------------------_is_valid_bst_---------------------//
template <typename T>
bool BST<T>::is_valid_bst()
{
    return is_valid_bst(root,  std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

template <typename T>
bool BST<T>::is_valid_bst(const Node* node, const T& min_val, const T& max_val) const
{
    if (node == nullptr)
    {
        return true;
    }

    if (node->val <= min_val || node->val >= max_val)
    {
        return false;
    }

    return is_valid_bst(node->left, min_val, node->val) && is_valid_bst(node->right, node->val, max_val);
}


//-----------------------------_level_order_------------------------//
template <typename T>
void BST<T>::level_order() const
{
    std::queue<Node*> nodes;
    
    nodes.push(root);

    while (!nodes.empty())
    {
        Node* node = nodes.front();
        if (node->left)
        {
            nodes.push(node->left);
        }
        if (node->right)
        {
            nodes.push(node->right);
        }
        std::cout << node->val << ' ';
        nodes.pop();
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


//-------------------------_contains_-------------------------//
template <typename T>
bool BST<T>::contains(const T& val)
{
    return search(root, val);
}


//------------------------_serialize_-------------------------//
template <typename T>
std::vector<T> BST<T>::serialize()
{  
    std::vector<T> vec;
    serialize(root, vec);
    return vec;
}

template <typename T>
void BST<T>::serialize(Node* root1, std::vector<T>& vec) 
{  

    if (!root1) {
        return;
    }
    inorder(root1->left);
    vec.emplace_back(root1->val);
    inorder(root1->right);
}


//

//-------------------------_get_root_------------------------//
template <typename T>
typename BST<T>::Node* BST<T>::get_root()
{
    return root;
}


//--------------------------_search_node_---------------------//
template <typename T>
typename BST<T>::Node* BST<T>::search_node(Node* root1, const T& val)
{
    if(root1 == nullptr)
    {
        return nullptr;
    }

    if(root1->val == val)
    {
        return root1;
    }

    if(root1->val < val)
    {
        return search_node(root1->right, val);
    }

    return search_node(root1->left, val);
}
