#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != nullptr)
            rightChild->left->parent = node;

        rightChild->parent = node->parent;

        if (node->parent == nullptr)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;

        rightChild->left = node;
        node->parent = rightChild;
    }

    // Hàm hỗ trợ xoay phải
    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != nullptr)
            leftChild->right->parent = node;

        leftChild->parent = node->parent;

        if (node->parent == nullptr)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;

        leftChild->right = node;
        node->parent = leftChild;
    }

    // Hàm hỗ trợ việc duy trì thuộc tính của cây Red-Black sau khi chèn một nút mới
    void fixInsert(Node* node) {
        while (node != root && node->parent->color == RED) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;

                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        rotateLeft(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateLeft(node->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    void insertNode(Node* newNode) {
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (newNode->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;

        if (parent == nullptr)
            root = newNode;
        else if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixInsert(newNode);
    }

public:
    Node* root;
    RedBlackTree() : root(nullptr) {}

    // Hàm chèn một giá trị mới vào cây Red-Black
    void insert(int data) {
        Node* newNode = new Node(data);
        insertNode(newNode);
    }
};
size_t caculate_height(Node *node){
        if(node == NULL)
            return 0;
        else
            return std::max(caculate_height(node->right),caculate_height(node->left))+1;
} 
int main() {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    return 0;
}