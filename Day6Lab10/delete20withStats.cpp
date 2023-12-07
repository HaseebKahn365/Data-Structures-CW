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
    Node *root;

public:
    int totalNodes;

    BST()
    {
        root = NULL;
        totalNodes = 0;
        noLeafNodesDeleted = noNodeWithOneChildDeleted = noNodeWithTwoChildren = 0;
    }

    //! Populating the tree with 1000 nodes with populate populateTree(int n):

    void populateTree(int limit)
    {

        while (totalNodes <= limit)
        {
            int randKey = rand() % 1000000; // increasing the random keys so that the program may terminate
            Node *temp = new Node(randKey, 'H');
            insert(temp);
        }
    }

    //! Attempting to delete 20 random nodes and showing stats:

    void delete20Random()
    {
        srand(time(0)); // Seed the random number generator once

        int totalBeforeDeletion = totalNodes;
        while (totalBeforeDeletion - totalNodes < 20)
        {
            int randKey = rand() % 200;
            deleteNode(randKey);
        }
        cout << "\n\n\nTotal Nodes before deletion\t| \t Total Nodes after deletion \t |\tNo of leaf Nodes Deleted \t |\tNo of deleted Nodes with one child \t |\tNo of deleted Nodes with two children \n\n\n";
        cout << "\t\t" << totalBeforeDeletion << "\t\t\t\t\t" << totalNodes << "\t\t\t\t\t" << noLeafNodesDeleted << "\t\t\t\t\t" << noNodeWithOneChildDeleted<< "\t\t"  << "\t\t\t" << noNodeWithTwoChildren<< "\t\t\n\n\n"  << endl;
    }

    Node *getRoot()
    {
        return root;
    }
    void insert(Node *i)
    {
        if (root == NULL)
        {
            // cout << "The new Node has been made a root element" << endl;
            root = i;
            totalNodes++;
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
                    // cout << "Invalid value! There can't be repeated keys" << endl;
                    return;
                }

                if (curr->key > i->key)
                {
                    // cout << "Going to the left of " << curr->key << endl;
                    curr = curr->left;

                    if (curr == NULL)
                    {
                        parent->left = i;
                        // cout << "Inserted at the left of " << parent->key << endl;
                        totalNodes++;
                        return;
                    }
                }
                else
                {
                    // cout << "Going to the right of " << curr->key << endl;
                    curr = curr->right;

                    if (curr == NULL)
                    {
                        parent->right = i;
                        // cout << "Inserted at the right of " << parent->key << endl;
                        totalNodes++;
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


void deleteNode(int key) {
    // Edge Cases.

    // If there are no nodes in tree
    if (root == NULL) {
        cout << "Tree is Empty." << endl;
        return;
    }

    Node *curr = root;
    Node *parent = root;
    Node *delNode = root;
    bool isLeft = true;

    // Searching for Key
    while (curr != NULL) {
        if (curr->key == key) {
            delNode = curr;
            break;
        }

        parent = curr;

        if (key < curr->key) {
            curr = curr->left;
            isLeft = true;
        } else {
            curr = curr->right;
            isLeft = false;
        }
    }

    // If key is not present in the tree.
    if (curr == NULL) {
        cout << "Key Not Found!" << endl;
        delete delNode;
        return;
    }

    // Case 1: Both left and right child are NULL of the deletion Node.
    else if (delNode->left == NULL && delNode->right == NULL) {
        if (delNode == root)
            root = NULL;
        else if (isLeft)
            parent->left = NULL;
        else
            parent->right = NULL;

        delete delNode;
        totalNodes--;
        noLeafNodesDeleted++;

        return;
    }

    // Case 2: Only Left Child is NULL
    else if (delNode->left == NULL) {
        if (isLeft)
            parent->left = delNode->right;
        else
            parent->right = delNode->right;

        delete delNode;
        totalNodes--;
        noNodeWithOneChildDeleted++;

        return;
    }

    // Case 3: Only Right Child is NULL
    else if (delNode->right == NULL) {
        if (isLeft)
            parent->left = delNode->left;
        else
            parent->right = delNode->left;

        delete delNode;
        totalNodes--;
        noNodeWithOneChildDeleted++;

        return;
    }

    // Case 4: None of right or left child are NULL
    else if (delNode->left != NULL && delNode->right != NULL) {
        Node *succ = curr->right;
        Node *par = succ;

        while (succ->left != NULL) {
            par = succ;
            succ = succ->left;
        }

        if (par == succ)
            delNode->right = succ->right;
        else
            par->left = succ->right;

        succ->left = delNode->left;
        succ->right = delNode->right;

        if (isLeft)
            parent->left = succ;
        else
            parent->right = succ;

        if (delNode == root)
            root = succ;

        delete delNode;
        totalNodes--;
        noNodeWithTwoChildren++;

        cout << root->key << endl;
    }
}


    //! The deletion function using recursion
    void deleteNodeWithRecursion(int key)
    {
        // modifying the root after deletion
        if (searchCheck(getRoot(), key))
        {
            totalNodes--;

            root = recursiveDeleteNodeWithKey(getRoot(), key);
        }
        else
        {

            cout << "Sorry no such key exists : " << key << endl;
        }
    }

private:
    int noLeafNodesDeleted, noNodeWithOneChildDeleted, noNodeWithTwoChildren;

    bool searchCheck(Node *root2, int key)
    {

        if (root2 == NULL)
            return false;
        if (root2->key == key)
        {
            return true;
        }
        if (root2->key > key)
        {
            return searchCheck(root2->left, key);
        }
        if (root2->key < key)
        {
            return searchCheck(root2->right, key);
        }
        return false;
    }

    Node *recursiveDeleteNodeWithKey(Node *root2, int key)
    {
        if (root2->key > key)
        {
            root2->left = recursiveDeleteNodeWithKey(root2->left, key);
        }
        else if (root2->key < key)
        {
            root2->right = recursiveDeleteNodeWithKey(root2->right, key);
        }
        else
        {
            // if root2->key == key:
            // case 1: leaf node deletion
            if (root2->left == NULL && root2->right == NULL)
            {
                return NULL;
            }

            // case 2: if root2 with one child
            if (root2->right == NULL)
            {
                return root2->left;
            }
            if (root2->left == NULL)
            {
                return root2->right;
            }

            // case3: if root2 with with two children
            Node *IS = inOrderSucessorFinder(root2->right);

            // copy the data from the inorder successor to the root2;
            root2->key = IS->key;
            root2->data = IS->data;

            // delete the IS from the bottom
            root2->right = recursiveDeleteNodeWithKey(root2->right, IS->key);
        }
        return root2;
    }

    Node *inOrderSucessorFinder(Node *succ)
    {
        while (succ->left != NULL)
        {
            succ = succ->left;
        }
        return succ;
    }
};

int main()
{
    BST *tree = new BST();

    // tree->insert(new Node(100, 'h'));
    //     tree->insert(new Node(50, 'h'));
    // tree->insert(new Node(120, 'h'));

    // tree->inOrder(tree->getRoot());
    // tree->deleteNode(100);
    //     tree->inOrder(tree->getRoot());
    //     cout<<"the end";

    
    tree->populateTree(10000);
    tree->delete20Random();

    return 0;
}