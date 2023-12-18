#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(-1) {} // Initialize height to -1
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = _insert(root, key);
    }

    void printPreOrder() {
                cout<<"root: "<<root->key<<endl;

        _printPreOrder(root);
        cout << endl;
    }

private:
    Node *root;

    int _height(Node *N) {
        return (N == nullptr) ? 0 : N->height;
    }

    Node *_rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(_height(y->left), _height(y->right)) + 1;
        x->height = max(_height(x->left), _height(x->right)) + 1;

        return x;
    }

    Node *_leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(_height(x->left), _height(x->right)) + 1;
        y->height = max(_height(y->left), _height(y->right)) + 1;

        return y;
    }

    int _getBalance(Node *N) {
        return (N == nullptr) ? 0 : _height(N->left) - _height(N->right);
    }

    Node *_insert(Node *node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else
            return node;

        // Update height of current node
        node->height = max(_height(node->left), _height(node->right)) + 1;

        // Get balance factor and perform rotations if needed
        int balance = _getBalance(node);

        if (balance > 1 && key < node->left->key)
            return _rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return _leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = _leftRotate(node->left);
            return _rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = _rightRotate(node->right);
            return _leftRotate(node);
        }

        return node;
    }

    void _printPreOrder(Node *root) {
        if (root != nullptr) {
            cout << root->height << " ";
            _printPreOrder(root->left);
            _printPreOrder(root->right);
        }
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(9);
    avlTree.insert(8);
    avlTree.insert(7);
    avlTree.insert(6);
    // avlTree.insert(5);
    //     avlTree.insert(4);
    // avlTree.insert(5);

    // avlTree.insert(40);
    // avlTree.insert(50);
    // avlTree.insert(60);
    // avlTree.insert(2);
    // avlTree.insert(23);

    cout << "Preorder traversal of the constructed AVL tree is\n";
    avlTree.printPreOrder();

    return 0;
}
