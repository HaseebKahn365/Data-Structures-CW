#include <iostream>
using namespace std;

class AVLTree {
public:
    class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
    };

    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = _insert(root, key);
    }

    void remove(int key) {
        root = _deleteNode(root, key);
    }

    void printPreOrder() {
        _printPreOrder(root);
        cout << endl;
    }
    Node* getRoot(){
        return root;
    }

private:
    Node *root;

    int _height(Node *N) {
        return (N == nullptr) ? -1 : N->height;
    }

    Node *newNode(int key) {
        return new Node(key);
    }

    Node *_rightRotate(Node *node) {
        Node *child = node->left;
        Node *T2 = child->right;

        child->right = node;
        node->left = T2;

        node->height = max(_height(node->left), _height(node->right)) + 1;
        child->height = max(_height(child->left), _height(child->right)) + 1;

        return child;
    }

    Node *_leftRotate(Node *node) {
        Node *child = node->right;
        Node *T2 = child->left;

        child->left = node;
        node->right = T2;

        node->height = max(_height(node->left), _height(node->right)) + 1;
        child->height = max(_height(child->left), _height(child->right)) + 1;

        return child;
    }

    int _getBalance(Node *N) {
        return (N == nullptr) ? 0 : _height(N->left) - _height(N->right);
    }

    Node *_insert(Node *node, int key) {
        if (node == nullptr)
            return newNode(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else
            return node;

        node->height = max(_height(node->left), _height(node->right)) + 1;

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

    Node *_deleteNode(Node *root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = _deleteNode(root->left, key);
        else if (key > root->key)
            root->right = _deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node *temp = (root->left) ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node *temp = _minValueNode(root->right);
                root->key = temp->key;
                root->right = _deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(_height(root->left), _height(root->right)) + 1;

        int balance = _getBalance(root);

        if (balance > 1 && _getBalance(root->left) >= 0)
            return _rightRotate(root);

        if (balance > 1 && _getBalance(root->left) < 0) {
            root->left = _leftRotate(root->left);
            return _rightRotate(root);
        }

        if (balance < -1 && _getBalance(root->right) <= 0)
            return _leftRotate(root);

        if (balance < -1 && _getBalance(root->right) > 0) {
            root->right = _rightRotate(root->right);
            return _leftRotate(root);
        }

        return root;
    }

    Node *_minValueNode(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    void _printPreOrder(Node *root) {
        if (root != nullptr) {
cout<<"["<<root->key<<"]\t";
            _printPreOrder(root->left);
            _printPreOrder(root->right);
        }
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(1);
    avlTree.insert(2);
    avlTree.insert(3);
    avlTree.insert(4);
    avlTree.insert(5);


    cout << "Preorder\n";
    cout<<"root: "<<avlTree.getRoot()->key<<endl;
    avlTree.printPreOrder();

    avlTree.remove(2);
    cout<<"deleting 2\n";

    cout << "\nPreorder\n";
    cout<<"root: "<<avlTree.getRoot()->key<<endl;
    avlTree.printPreOrder();

    return 0;
}
