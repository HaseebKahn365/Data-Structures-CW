
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int bal_fact;
    int height;
    Node *lChild;
    Node *rChild;

    Node(int key)
    {
        this->key = key;
        bal_fact = 0;
        height = 0;
        lChild = NULL;
        rChild = NULL;
    }

    void display()
    {
        cout << key << " " << bal_fact << " " << height << endl;
    }
};

class AVLTree
{
    Node *root;

public:
    AVLTree()
    {
        root = NULL;
    }

    bool shouldInsert(Node *newNode)
    {
        if (newNode == NULL)
        {
            return false;
        }
        else
            root = _insert(root, newNode);
        return true;
    }

    void display()
    {
        _display(root);
    }

    void deleteNode(int key)
    {
        if (root == NULL)
        {
            cout << "Tree is Empty" << endl;
            return;
        }

        root = _deleteNode(root, key);
        cout << root->key << endl;
    }

private:
    Node *_insert(Node *node, Node *newNode)
    {
        if (node == NULL)
            return newNode;
        if (newNode->key < node->key)
            node->lChild = _insert(node->lChild, newNode);
        else
            node->rChild = _insert(node->rChild, newNode);

        _update(node);
        return _balance(node);
    }

    Node *_deleteNode(Node *node, int key)
    {
        if (node->key == key)
        {
            // if both of the children are null
            if (node->lChild == NULL && node->rChild == NULL)
                return NULL;
            // if only the right child is null
            else if (node->rChild == NULL)
                return node->lChild;

            // if only the left child is null
            else if (node->lChild == NULL)
                return node->rChild;

            else
            {
                Node *successor = _findMax(node->rChild);
                successor->rChild = _deleteNode(node->rChild, successor->key);
                successor->lChild = node->lChild;
                _update(successor);
                return _balance(successor);
            }
        }
        else if (key < node->key)
            node->lChild = _deleteNode(node->lChild, key);
        else
            node->rChild = _deleteNode(node->rChild, key);
        // after deletion updae and balance the tree;
        _update(node);
        return _balance(node);
    }

    void _update(Node *node)
    {
        int lh = -1;
        int rh = -1;

        if (node->lChild != NULL)
        {
            lh = node->lChild->height;
        }
        if (node->rChild != NULL)
        {
            rh = node->rChild->height;
        }
        node->height = 1 + max(lh, rh);
        node->bal_fact = rh - lh;
    }

    Node *_balance(Node *node)
    {
        // left-heavy
        if (node->bal_fact == -2)
        {
            cout << "left is heavy of " << node->key << endl;
            if (node->lChild->bal_fact <= 0)
            {
                cout << "Left left case " << endl;
                return _leftLeftCase(node); // single right rotation
            }
            else
            {
                cout << "Left Right Case" << endl;
                return _leftRightCase(node);
            }
        }
        // right heavy
        else if (node->bal_fact == 2)
        {
            cout << "right heavy of " << node->key << endl;
            if (node->rChild->bal_fact >= 0)
            {
                cout << "Right Right case " << endl;
                return _rightRightCase(node);
            }
            else
            {
                cout << "Right left Case" << endl;
                return _rightLeftCase(node);
            }
        }

        return node;
    }

    Node *_leftLeftCase(Node *node)
    {
        return _rightRotate(node);
    }

    Node *_rightRightCase(Node *node)
    {
        return _leftRotate(node);
    }

    Node *_leftRightCase(Node *node)
    {
        node->lChild = _leftRotate(node);
        return _rightRotate(node);
    }
    Node* _rightLeftCase(Node* node)
    {
        node->lChild = _rightRotate(node);
        return _leftRotate(node);
    }

    Node* _rightRotate(Node* node)
    {
        Node* left =  node->lChild;
        Node* temp = left->rChild;
        left->rChild =node;
        node->lChild = temp;

        _update(node);
        _update(left);
        return left;
    }

    Node* _leftRotate(Node* node)
    {
        Node* right = node->lChild;
        Node* temp = node->lChild;
        right->lChild = node;
        node->rChild = temp;

        _update(node);
        _update(right);

        return right;
    }

    Node* _findMax(Node* node){
        while(node->rChild)
            node = node->rChild;

        return node;
    }

    void _display(Node* node)
    {
        if(node == NULL)
            return;
        _display(node->lChild);
        node->display();
        _display(node->rChild);
    }
};

int main()
{
    AVLTree* AVLT = new AVLTree();
    AVLT->shouldInsert(new Node(50));
    AVLT->display(); 

    AVLT->shouldInsert(new Node(70));
    AVLT->shouldInsert(new Node(5));

    return 0;
}