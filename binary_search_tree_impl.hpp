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
BST<T>::Node::~Node()
{
    delete left;
    delete right;
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

template <class T>
void BST<T>::insert(const T& val1) 
{
    if (val1 < 0)
    {
        std::cout << "in BST/insert\nval must be >=0" << std::endl;
        exit(0);
    }

    root = insert_rec(root, val1);

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

template <class T>
typename BST<T>::Node* BST<T>::get_root()
{
    return root;
}


// template <class T>
// typename BST<T>::Node* BST<T>::insert_rec(Node* node1, const T& val1)
// {
//     if (node1 == nullptr)
//     {
//         return new Node(val1, nullptr, nullptr);
//     }

//     if (val1 < node1->val) {
//         node1->left = insert_rec(node1->left, val1);
//     } else if (val1 > node1->val) {
//         node1->right = insert_rec(node1->right, val1);
//     }

//     return node1;
// }

template <class T>
typename BST<T>::Node* BST<T>::insert_rec(Node* node1, const T& val1)
{
    if (node1 == nullptr)
    {
        return new Node(val1, nullptr, nullptr);
    }

    if (val1 < node1->val) {
        node1->left = insert_rec(node1->left, val1);
    } else if (val1 > node1->val) {
        node1->right = insert_rec(node1->right, val1);
    } else {
        // Handle duplicates as needed
        // For example, you can choose to ignore duplicates or update the existing node
        // For now, let's ignore duplicates
        return node1;
    }

    return node1;
}


template <class T>
void BST<T>::inorder()
{
    Node* tmp = root;
    inorder(tmp);

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

