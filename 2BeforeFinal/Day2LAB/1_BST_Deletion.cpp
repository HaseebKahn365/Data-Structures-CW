#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    char data;
    Node *right = NULL;
    Node *left = NULL;
    Node(int k, char c) : key(k), data(c) {}
    void display()
    {
        cout << "Node with key= " << key << " and data= " << data << endl;
    }
};

class BST
{
    Node *root = NULL;

public:
    void insert(Node *i)
    {
        if (root == NULL)
        {
            cout << "The new Node has been made a root element" << endl;
            root = i;
        }
        else
        {
            Node *parent = NULL;
            Node *curr = root;

            while (1)
            {
                parent = curr;

                if (curr->key == i->key)
                {
                    cout << "Invalid value! There can't be repeated keys" << endl;
                    return;
                }

                if (curr->key > i->key)
                {
                    cout << "Going to the left of " << curr->key << endl;
                    curr = curr->left;

                    if (curr == NULL)
                    {
                        parent->left = i;
                        cout << "Inserted at the left of " << parent->key << endl;
                        return;
                    }
                }
                else
                {
                    cout << "Going to the right of " << curr->key << endl;
                    curr = curr->right;

                    if (curr == NULL)
                    {
                        parent->right = i;
                        cout << "Inserted at the right of " << parent->key << endl;
                        return;
                    }
                }
            }
        }
    }

    void inOrder(Node *n)
    {
        if (n == NULL)
            return;
        inOrder(n->left);
        n->display();
        inOrder(n->right);
    }

    Node *search(int key)
    {
        // if(root == NULL) cout<<"Exception: The root is null"<<endl;
        Node *parent, *curr;
        parent = curr = root;

        while (1)
        {
            if (curr == NULL)
                return NULL;
            if (curr->key == key)
            {
                cout << "The key has been found" << endl;
                return curr;
            }

            if (curr->key > key)
            {
                // look on the left side;
                //  if(curr = NULL) return NULL;
                curr = curr->left;
            }
            else if (curr->key < key)
            {
                // look on the right side:
                //  if(curr == NULL) return NULL;
                curr = curr->right;
            }
        }
    }

    Node *searchRecursive(int key, Node *n)
    {

        if (n->key == key)
        {
            return n;
        }
        if (n->key != key && n == NULL)
            return NULL;
        if (n->key > key)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
         searchRecursive(key, n);
    }
    //delete the node with the given key using recursion

    void deleteNode(int key)
    {
        Node *curr = root;
        Node *parent = NULL;

        while (curr != NULL && curr->key != key)
        {
            parent = curr;
            if (key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (curr == NULL)
        {
            cout << "Key not found" << endl;
            return;
        }

        if (curr->left == NULL && curr->right == NULL)
        {
            if (parent == NULL)
                root = NULL;
            else if (parent->left == curr)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (curr->left == NULL)
        {
            if (parent == NULL)
                root = curr->right;
            else if (parent->left == curr)
                parent->left = curr->right;
            else
                parent->right = curr->right;
        }
        else if (curr->right == NULL)
        {
            if (parent == NULL)
                root = curr->left;
            else if (parent->left == curr)
                parent->left = curr->left;
            else
                parent->right = curr->left;
        }
        else
        {
            Node *succParent = curr;
            Node *succ = curr->right;

            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != curr)
            {
                succParent->left = succ->right;
            }
            else
            {
                succParent->right = succ->right;
            }

            succ->left = curr->left;
            succ->right = curr->right;

            if (parent == NULL)
                root = succ;
            else if (parent->left == curr)
                parent->left = succ;
            else
                parent->right = succ;
        }

        delete curr;
    }

 //root getter
    Node *getRoot()
    {
        return root;
    }

    //dete the node with the given key

    
};

int main()
{
    BST *tree = new BST();
    tree->insert(new Node(50, 'h'));
    tree->insert(new Node(75, 'a'));
    tree->insert(new Node(30, 's'));
    tree->insert(new Node(45, 's'));
    tree->insert(new Node(24, 's'));
     tree->insert(new Node(27, 's'));
      tree->insert(new Node(21, 'k'));
       tree->insert(new Node(10, 'b'));


    cout << "Here we are finding a node with the key value of 45" << endl;
    Node* temp = tree->searchRecursive(45, tree->getRoot());
    if (temp)
        temp->display();
    else
        cerr << "Hello" << endl;
    cout << "Here we are deleting a node with the key value of 45" << endl;
    tree->deleteNode(45);
    tree->inOrder(tree->getRoot());
        

    return 0;
}