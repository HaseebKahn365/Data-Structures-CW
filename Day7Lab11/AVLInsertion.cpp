#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k): key(k), left(NULL), right(NULL), height(-1){}

};

class AVLTree{
    private:
    Node* root;

    public:

    void insert(int key)
    {
        root = _insert(root, key);
    }
    void printInOrder(){
        cout<<"Root: "<<root->key<<endl;
        cout<<endl;
        _inOrder(root);
    }

    private:
    void _inOrder(Node* root){
        if(root ==NULL) return;
        _inOrder(root->left);
        cout<<"["<<root->key<<"]\t";
        _inOrder(root->right);
    }
    int _height(Node* N){
        return (N== NULL)? 0: N->height;
    }

    int _getBal(Node* n){
        return (n == NULL)? 0 : _height(n->left) - _height(n->right);
    }

    //right rotation

        Node *_rotateRight(Node *A) {
        Node *B = A->left;
        Node *BsubT = B->right;

        // Perform rotation
        B->right = A;
        A->left = BsubT;

        // Update heights
        A->height = max(_height(A->left), _height(A->right)) + 1;
        B->height = max(_height(B->left), _height(B->right)) + 1;

        return B;
    }

    Node *_rotateLeft(Node *A) {
        Node *B = A->right;
        Node *BsubT = B->left;

        // Perform rotation
        B->left = A;
        A->right = BsubT;

        // Update heights
        A->height = max(_height(A->left), _height(A->right)) + 1;
        B->height = max(_height(B->left), _height(B->right)) + 1;

        return B;
    }




    Node* _insert(Node* node, int key)
    {
        if(node == NULL)
            return new Node(key);
        if(key<node->key) node->left = _insert(node->left , key);
        else if(key > node->key) node->right = _insert(node->right, key);
        else {
            cout<<"key already exists";
            return node;
        };

        node->height = max(_height(node->left), _height(node->right))+1;

        int bf = _getBal(node);   
        //left left imbalance
        if(bf > 1 && key< node->left->key) return _rotateRight(node);
        //right right imbalance
        if(bf < -1 && key> node->right->key) return _rotateLeft(node);
        // < shape case
        if(bf >1 && key>node->left->key ){
            node->left= _rotateLeft(node->left);
            return _rotateRight(node);
        }
        // > shape case
        if(bf <-1 && key < node->right->key) {
            node->right = _rotateRight(node->right);
            return _rotateLeft(node);
        }

        return node;

    }

    

};

int main(){
    AVLTree* myTree = new AVLTree();
    //Testing the right rotate:
    // myTree->insert(12);
    // myTree->insert(13);
    // myTree->insert(14);
    // myTree->insert(15);
    // myTree->printInOrder();
    //Testing the left rotate:
    myTree->insert(9);
    myTree->insert(8);
    myTree->insert(7);
    myTree->insert(6);
    // myTree->insert(5);
    // myTree->insert(4);
    // myTree->insert(3);
    myTree->printInOrder();
    return 0;
}