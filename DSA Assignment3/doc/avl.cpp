#include <iostream>
#include <string>
using namespace std;

class Prefference{
    public:
    bool wifi;
    bool bluetooth;
    int heaterTemp;
    int lightSetIntensity;
    bool tv;
    bool usesLaptop;
    bool usesPhone;
    bool usesTablet;
    bool usesPC;
    Prefference(){
        wifi = false;
        bluetooth = false;
        heaterTemp = 0;
        lightSetIntensity = 0;
        tv = false;
        usesLaptop = false;
        usesPhone = false;
        usesTablet = false;
        usesPC = false;
    }
    //setter for all the services
    void setWifi(bool w){
        wifi = w;
    }

    void setBluetooth(bool b){
        bluetooth = b;
    }

    void setHeaterTemp(int t){
        heaterTemp = t;
    } 

    void setLightSetIntensity(int i){
        lightSetIntensity = i;
    }

    void setTv(bool t){
        tv = t;
    }

    void setUsesLaptop(bool l){
        usesLaptop = l;
    }

    void setUsesPhone(bool p){
        usesPhone = p;
    }

    void setUsesTablet(bool t){
        usesTablet = t;
    }

    void setUsesPC(bool p){
        usesPC = p;
    }


};



class HNodePref {
public:
    int pref_id;
    Prefference pref;

    HNodePref(int id, Prefference p) : pref_id(id), pref(p), left(nullptr), right(nullptr) {}

    HNodePref* left;
    HNodePref* right;

    int height;

    HNodePref(int k, Prefference p) : pref_id(k), pref(p), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    void insert(int key, HNodePref* hNode) {
        root = _insert(root, key, hNode);
    }

    void remove(int key) {
        root = _deleteNode(root, key);
    }

    void printPreOrder() {
        _printPreOrder(root);
        cout << endl;
    }

private:
    HNodePref* root;

    int _height(HNodePref* N) {
        return (N == nullptr) ? 0 : N->height;
    }

    int _max(int a, int b) {
        return (a > b) ? a : b;
    }

    HNodePref* newNode(int key, Prefference p) {
        return new HNodePref(key, p);
    }

    HNodePref* _rightRotate(HNodePref* y) {
        HNodePref* x = y->left;
        HNodePref* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = _max(_height(y->left), _height(y->right)) + 1;
        x->height = _max(_height(x->left), _height(x->right)) + 1;

        return x;
    }

    HNodePref* _leftRotate(HNodePref* x) {
        HNodePref* y = x->right;
        HNodePref* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = _max(_height(x->left), _height(x->right)) + 1;
        y->height = _max(_height(y->left), _height(y->right)) + 1;

        return y;
    }

    int _getBalance(HNodePref* N) {
        return (N == nullptr) ? 0 : _height(N->left) - _height(N->right);
    }

    HNodePref* _insert(HNodePref* node, int key, HNodePref* hNode) {
        if (node == nullptr)
            return newNode(key, hNode->pref);

        if (key < node->pref_id)
            node->left = _insert(node->left, key, hNode);
        else if (key > node->pref_id)
            node->right = _insert(node->right, key, hNode);
        else
            return node;

        node->height = _max(_height(node->left), _height(node->right)) + 1;

        int balance = _getBalance(node);

        if (balance > 1 && key < node->left->pref_id)
            return _rightRotate(node);

        if (balance < -1 && key > node->right->pref_id)
            return _leftRotate(node);

        if (balance > 1 && key > node->left->pref_id) {
            node->left = _leftRotate(node->left);
            return _rightRotate(node);
        }

        if (balance < -1 && key < node->right->pref_id) {
            node->right = _rightRotate(node->right);
            return _leftRotate(node);
        }

        return node;
    }

    HNodePref* _deleteNode(HNodePref* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->pref_id)
            root->left = _deleteNode(root->left, key);
        else if (key > root->pref_id)
            root->right = _deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                HNodePref* temp = (root->left) ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                HNodePref* temp = _minValueNode(root->right);
                root->pref_id = temp->pref_id;
                root->right = _deleteNode(root->right, temp->pref_id);
            }
        }

        if (root == nullptr)
            return root;

        root->height = _max(_height(root->left), _height(root->right)) + 1;

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

    HNodePref* _minValueNode(HNodePref* node) {
        HNodePref* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    void _printPreOrder(HNodePref* root) {
        if (root != nullptr) {
            cout << root->pref_id << " ";
            _printPreOrder(root->left);
            _printPreOrder(root->right);
        }
    }
};
