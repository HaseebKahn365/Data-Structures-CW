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
    Node *getRoot()
    {
        return root;
    }
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

    // tree traversals in BST:
    // preorder: root-> left -> right

    void preOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->key << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }

    // in-order traversal
    void inOrder(Node *n)
    {
        if (n == NULL)
            return;

        inOrder(n->left);
        cout << n->key << "\t";
        inOrder(n->right);
    }
    // post-order traversal:
    void postOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        postOrder(n->right);
        cout << n->key << "\t";
        postOrder(n->left);
    }

    // breadth-first traversal using recursion:
    void breadthFirst(Node *n)
    {
        if (n == NULL)
            return;
        cout << n->key << "\t";
        breadthFirst(n->left);
        breadthFirst(n->right);
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

    //! The deletion function:

    void deleteNode(int key)
    {
        // Searching for the Node:

        Node *parent = root; // this is the parent of the delnode
        Node *curr = root;   // this is the iterator
        bool isLeft = true;
        Node *delNode = root;

        while (curr != NULL)
        {
            if (key == curr->key)
            {
                delNode = curr; // delnode found!
                break;          // to get out of the loop
            }
            parent = curr; // parent is above the left or right child to be deleted

            if (key > curr->key)
            {
                curr = curr->right;
                isLeft = false;
            }
            else
            {
                curr = curr->left;
                isLeft = true;
            }
        }

        // check if not found:
        if (curr == NULL)
        {
            cout << "Sorry No item found with key " << key << endl;
        }

        // Case 1: check if leaf node:
        if (delNode->left == NULL && delNode->right == NULL)
        {
            // if the deleted node is the root node:
            if (delNode == root)
                root = NULL;

            // if the deleteNode is on the left of parent
            else if (isLeft)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }

            //delete the object from the memory:
            cout<<"deleted Leaf"<<endl;
            delete delNode;

            return; //Job done for the leafNode
        }


        //Case 2: Deleting Node with 1 child
         if(delNode->right != NULL || delNode->right == NULL){

            if(delNode->right == NULL){
                
            }
         }

    } //end of delete()







};

int main()
{
    BST *tree = new BST();
    tree->insert(new Node(100, 'h'));
    // tree->insert(new Node(50, 'a'));
    // tree->insert(new Node(90, 's'));
    // tree->insert(new Node(25, 'e'));
    // tree->insert(new Node(60, 'e'));
    // tree->insert(new Node(40, 'b'));
    // tree->insert(new Node(65, 'k'));
    // tree->insert(new Node(10, 'h'));
    // tree->insert(new Node(29, 'a'));

    // tree->search(45)->display();
    // tree->search(24)->display();
    // if((tree->search(21)) == NULL){
    //     cout<<"Nothing found!"<<endl;
    // }

    // tree->breadthFirst(tree->getRoot());
    tree->inOrder(tree->getRoot());
    cout << "\nEnd of the post order:";
    tree->deleteNode(100);
    tree->inOrder(tree->getRoot());

    return 0;
}