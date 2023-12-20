template <class T>
BST<T>::BST() :
    root(nullptr)
{}

template <class T>
BST<T>::~BST()
{
    clear(root);
}

template <class T>
BST<T>::Node::Node() : 
    left(nullptr),
    right(nullptr),
    val(0)
{}

template <class T>
BST<T>::Node::Node(T val1, Node* left1, Node* right1) :
    left(left1),
    right(right1),
    val(val1)
{}  


//----------------_clear_---------------------//
template <class T>
void BST<T>::clear()
{
    clear(root);
}

template <class T>
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
template <class T>
void BST<T>::insert(const T& val1) 
{
    if (val1 < 0)
    {
        std::cout << "in BST/insert\nval must be >=0" << std::endl;
        exit(0);
    }

    root = insert(root, val1);

}

template <class T>
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


//-----------------------_delete__________________________//
template <class T>
void BST<T>::Delete(const T& val)
{
    root = Delete(val, root);
}

template <class T>
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
template <class T>
bool BST<T>::search(const T& val)
{
    return search(root, val);
}

template <class T>
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
template <class T>
void BST<T>::inorder()
{
    inorder(root);
    std::cout << std::endl;
}

template <class T>
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
template <class T>
void BST<T>::pre_order()
{
    pre_order(root);
    std::cout << std::endl;
}

template <class T>
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
template <class T>
void BST<T>::post_order()
{
    post_order(root);
    std::cout << std::endl;
}

template <class T>
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
template <class T>
typename BST<T>::Node* BST<T>::find_min()
{
    return find_min(root);
}

template <class T>
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
template <class T>
typename BST<T>::Node* BST<T>::find_max()
{
    return find_max(root);
}

template <class T>
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
template <class T>
int BST<T>::height()
{
    return height(root);
}

template <class T>
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

        std::cout << "root->val   " << root1->val << std::endl;
        std::cout << "leftH   " << leftH << std::endl;
        std::cout << "rightH   " << rightH << std::endl;

        return std::max(leftH, rightH) + 1;
    }
}


//--------------------------_successor_-----------------------//
template <class T>
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
template <class T>
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


}


//-------------------------_get_root_------------------------//
template <class T>
typename BST<T>::Node* BST<T>::get_root()
{
    return root;
}

//--------------------------_search_node_---------------------//
template <class T>
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
