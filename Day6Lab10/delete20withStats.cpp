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

    void populateTree(int limit)
    {

        while (totalNodes < limit)
        {
            int randKey = rand() % 1000000;
            Node *temp = new Node(randKey, 'H');
            insert(temp);
        }
    }

    void delete20Random()
    {
        srand(time(0));

        int totalBeforeDeletion = totalNodes;
        while (totalBeforeDeletion - totalNodes < 20)
        {
            int randKey = rand() % 200;
            deleteNode(randKey);
        }
        cout << "\n\n\nTotal Nodes before deletion\t| \t Total Nodes after deletion \t |\tNo of leaf Nodes Deleted \t |\tNo of deleted Nodes with one child \t |\tNo of deleted Nodes with two children \n\n\n";
        cout << "\t\t" << totalBeforeDeletion << "\t\t\t\t\t" << totalNodes << "\t\t\t\t\t" << noLeafNodesDeleted << "\t\t\t\t\t" << noNodeWithOneChildDeleted << "\t\t"
             << "\t\t\t" << noNodeWithTwoChildren << "\t\t\n\n\n"
             << endl;
    }

    Node *getRoot()
    {
        return root;
    }
    void insert(Node *i)
    {
        if (root == NULL)
        {

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

                    return;
                }

                if (curr->key > i->key)
                {

                    curr = curr->left;

                    if (curr == NULL)
                    {
                        parent->left = i;

                        totalNodes++;
                        return;
                    }
                }
                else
                {

                    curr = curr->right;

                    if (curr == NULL)
                    {
                        parent->right = i;

                        totalNodes++;
                        return;
                    }
                }
            }
        }
    }

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

    void inOrder(Node *n)
    {
        if (n == NULL)
            return;

        inOrder(n->left);
        cout << n->key << "\t";
        inOrder(n->right);
    }

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

                curr = curr->left;
            }
            else if (curr->key < key)
            {

                curr = curr->right;
            }
        }
    }

    void deleteNode(int key)
    {

        if (root == NULL)
        {
            cout << "Root is null nothing is here" << endl;
            return;
        }

        Node *curr = root;
        Node *parent = root;
        Node *delNode = root;
        bool isLeft = true;

        while (curr != NULL)
        {
            if (curr->key == key)
            {
                delNode = curr;
                break;
            }

            parent = curr;

            if (key < curr->key)
            {
                curr = curr->left;
                isLeft = true;
            }
            else
            {
                curr = curr->right;
                isLeft = false;
            }
        }

        if (curr == NULL)
        {
            cout << "No such key as: " << key << endl;
            delete delNode;
            return;
        }

        else if (delNode->left == NULL && delNode->right == NULL)
        {
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

        else if (delNode->left == NULL)
        {
            if (isLeft)
                parent->left = delNode->right;
            else
                parent->right = delNode->right;

            delete delNode;
            totalNodes--;
            noNodeWithOneChildDeleted++;

            return;
        }

        else if (delNode->right == NULL)
        {
            if (isLeft)
                parent->left = delNode->left;
            else
                parent->right = delNode->left;

            delete delNode;
            totalNodes--;
            noNodeWithOneChildDeleted++;

            return;
        }

        else if (delNode->left != NULL && delNode->right != NULL)
        {
            Node *succ = curr->right;
            Node *par = succ;

            while (succ->left != NULL)
            {
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

    void deleteNodeWithRecursion(int key)
    {

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

            if (root2->left == NULL && root2->right == NULL)
            {
                return NULL;
            }

            if (root2->right == NULL)
            {
                return root2->left;
            }
            if (root2->left == NULL)
            {
                return root2->right;
            }

            Node *IS = inOrderSucessorFinder(root2->right);

            root2->key = IS->key;
            root2->data = IS->data;

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

    tree->populateTree(10000);
    tree->delete20Random();

    return 0;
}