#include <iostream>
using namespace std;

class Node
{
public:
    int prefId;
    Node *left;
    Node *right;

    Node(int pid)
    {
        this->prefId = pid;
        this->left = this->right = nullptr;
    }
};

class BinarySearchTree
{
    Node *root = nullptr;

public:
    void insert(Node *n)
    {
        root = _recursiveInsert(getRoot(), n);
    }

    void inOrder()
    {
        cout << "Root: " << getRoot()->prefId << endl;
        _inOrder(getRoot());
    } 

    void deleteNode(int prefId)
    {
        root = _deleteNode(getRoot(), prefId);
    }

    bool _search(Node *root, int prefuid)
    {
        if (root == nullptr)
            return false;
        if (prefuid == root->prefId)
            return true;
        else if (prefuid > root->prefId)
            return _search(root->right, prefuid);
        else
            return _search(root->left, prefuid);
    }

    

    Node *getRoot()
    {
        return root;
    }

       void doCounting(){
        countNNode(root, leafNodes, child1, child2);
        cout<<"\nleafnodes = "<<leafNodes<<"\nchild1 = "<<child1<<"\nchild2 = "<<child2<<endl;
    }
private:

    Node *_recursiveInsert(Node *root, Node *n)
    {
        if (root == nullptr)
        {
            root = n;
            return root;
        }
        else if (root->prefId > n->prefId)
        {
            root->left = _recursiveInsert(root->left, n);
        }
        else if(root->prefId < n->prefId)
        {
            root->right = _recursiveInsert(root->right, n);
        }
            if(root->prefId == n->prefId) cout<<"Invalid node"<<endl;
        

        return root;
    }

    void _inOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        _inOrder(root->left);
        cout << "[ " << root->prefId << " ]"
             << "\t";
        _inOrder(root->right);
    }



   Node *_deleteNode(Node *root, int prefId)
{
    if (root == nullptr)
    {
        cout << "No node found with key: " << prefId << endl;
        return root;  // Return root as it is unchanged
    }

    if (prefId < root->prefId)
    {
        root->left = _deleteNode(root->left, prefId);
    }
    else if (prefId > root->prefId)
    {
        root->right = _deleteNode(root->right, prefId);
    }
    else
    { // case1: if leaf node:
        if (root->right == nullptr && root->left == nullptr)
        {
            delete root;
            // return nullptr;
        }
        // case2: if node with one child:
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // case3: if node with two children
        else
        {
            Node *IS = _findSucc(root->right);
            // replacing the data with that of successor:
            root->prefId = IS->prefId;
            // remove the IS in the subtrees using case 1 or 2
            root->right = _deleteNode(root->right, IS->prefId);
        }
    }
    return root;
}
    Node *_findSucc(Node *n)
    {
        while (n->left != NULL)
        {
            n = n->left;
        }
        return n;
    }

     int leafNodes =0; int child1 =0; int child2 =0;
    void countNNode(Node* n, int &leafNodes, int &child1, int &child2)
    {
        if(n==NULL) return;
        countNNode(n->left, leafNodes, child1, child2);

        if(n->left ==NULL && n->right==NULL) {
            leafNodes++;
        }
        else if(n->left==NULL || n->right ==NULL){
            child1++;
        }
        else{
            child2++;
        }
        countNNode(n->right,leafNodes, child1, child2);

    }

};

int main()
{
    BinarySearchTree *Tree = new BinarySearchTree();
    Tree->insert(new Node(1));
    Tree->insert(new Node(3));
    Tree->insert(new Node(2));
    Tree->insert(new Node(5));
    Tree->insert(new Node(7));
    Tree->insert(new Node(7));
    // if(Tree->_search( Tree->getRoot(), 7)) cout<<"yeas found 7"<<endl;
    // cout << "Printing..." << endl;
    // Tree->insert(new Node(8));
    // Tree->inOrder();
    // Tree->deleteNode(9);
    // cout << endl;
    // Tree->insert(new Node(9));
    Tree->inOrder();

    Tree->doCounting();

    return 0;
}
