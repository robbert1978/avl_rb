#include <iostream>

struct AVLNode
{
    public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;
};
 
int height(AVLNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
 
AVLNode* newNode(int key)
{
    AVLNode* node = new AVLNode();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
 
AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = std::max(height(y->left),
                    height(y->right)) + 1;
    x->height = std::max(height(x->left),
                    height(x->right)) + 1;
 
    return x;
}
 
AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = std::max(height(x->left),   
                    height(x->right)) + 1;
    y->height = std::max(height(y->left),
                    height(y->right)) + 1;
 
    return y;
}
 
int getBalance(AVLNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

AVLNode* insert(AVLNode* node, int key)
{
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + std::max(height(node->left),
                        height(node->right));
 
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
void preOrder(AVLNode *root)
{
    if(root != NULL)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
size_t caculate_height(AVLNode* node){
    if(node == NULL)
        return 0;
    else
        return std::max(caculate_height(node->right),caculate_height(node->left))+1;
} 
int main()
{
    AVLNode *root = NULL;
    size_t N = 0;
    int in_key;
    std::cin >> N;
    for(size_t i = 0 ; i < N ; ++i){
        std::cin >> in_key;
        root = insert(root,in_key);
    }
    preOrder(root);
    putchar(10);
    std::cout << root->height << '\n';
    std::cout << caculate_height(root) << '\n';
    return 0;
}
 