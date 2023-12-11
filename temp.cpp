#include <iostream>
#include <random>

using namespace std;

class Node
{
public:
    int key;

    Node *lChild;
    Node *rChild;

    Node(int key)
    {
        this->key = key;
        lChild = rChild = NULL;
    }
};

class Tree
{
private:
    Node *root;
    int size;

public:
    Tree()
    {
        root = NULL;
        size = 0;
    }

    bool insert(Node *newNode)
    {
        if (newNode == NULL)
            return false;

        else
            root = _insert(root, newNode);

        size++;

        return true;
    }

    void remove(int key, int arr[])
    {
        if (!root)
        {
            cerr << "Tree is Empty" << endl;
            return;
        }

        size--;

        root = _deleteNode(root, key, arr);
    }

    bool search(int key)
    {
        Node *node = root;

        while (node != NULL)
        {
            if (key == node->key)
                return true;
            else if (key > node->key)
                node = node->rChild;
            else
                node = node->lChild;
        }

        return false;
    }

    int getSize()
    {
        return size;
    }

    // ~Tree()
    // {
    //     cout << "\nTree Cut Sho" << endl;
    // }

private:
    Node *_insert(Node *node, Node *newNode)
    {
        if (node == NULL)
            return newNode;

        if (newNode->key < node->key)
            node->lChild = _insert(node->lChild, newNode);
        else
            node->rChild = _insert(node->rChild, newNode);

        return node;
    }

    Node *_deleteNode(Node *node, int key, int arr[])
    {
        if (node == NULL)
        {
            cout << "Node with Key = " << key << " not found!" << endl;
            return NULL;
        }

        if (node->key == key)
        {
            if (node->lChild == NULL && node->rChild == NULL)
            {
                arr[0]++;
                return NULL;
            }

            else if (!node->rChild)
            {
                arr[1]++;
                return node->lChild;
            }

            else if (!node->lChild)
            {
                arr[1]++;
                return node->rChild;
            }

            else
            {
                Node *successor = _findSuccessor(node->rChild);

                arr[2]++;

                successor->rChild = _deleteNode(node->rChild, successor->key, arr);

                successor->lChild = node->lChild;

                return successor;
            }
        }

        else if (key < node->key)
            node->lChild = _deleteNode(node->lChild, key, arr);

        else
            node->rChild = _deleteNode(node->rChild, key, arr);
    }

    Node *_findSuccessor(Node *node)
    {
        while (node->lChild < NULL)
            node = node->lChild;

        return node;
    }
};

int insertionOfNodes(Tree &tree, int noOfNodes)
{
    for (size_t i = 0; i < noOfNodes; i++)
    {
        int key = rand() % 10000;

        if (tree.search(key))
            i--;
        else
            tree.insert(new Node(key));
    }

    return tree.getSize();
}

int deleteRandom(Tree &tree, int noOfNodes, int arr[3])
{
    for (size_t i = 0; i < noOfNodes; i++)
    {
        int key = rand() % 10000;

        if (tree.search(key))
            tree.remove(key, arr);
        else
            i--;
    }

    return tree.getSize();
}

int main()
{
    Tree tree;
    int arr[3] = {3, 9, 8};

    insertionOfNodes(tree, 1000);

    deleteRandom(tree, 20, arr);

    cout << "Syntax Error!!" << endl;

    return 0;
}