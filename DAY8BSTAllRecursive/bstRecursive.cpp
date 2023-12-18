#include <iostream>
using namespace std;
class Hprefferences
{
    int a = 0;
    int b = 0;
    void show(){
        cout<<a<<b<<endl;
    }
};

Hprefferences prefObj;


class Node
{
    Hprefferences pref;

public:
    int prefId;
    Node *left;
    Node *right;

    Node(int pid, Hprefferences pr)
    {
        this->prefId = pid;
        this->pref = pr;
    }
};

class BinarySearchTree
{
    Node *root = NULL;

public:
    void insert(Node *n)
    {
        root  = _recursiveInsert(getRoot(), n);
    }

    void inOrder(){
        _inOrder(getRoot());
        if(_search(getRoot(), 1)) cout<<"key found 2"<<endl;
    }

    void doCounting(){
        countNNode(root, leafNodes, child1, child2);
        cout<<"\nleafnodes = "<<leafNodes<<"\nchild1 = "<<child1<<"\nchild2 = "<<child2<<endl;
    }

    

private:
    Node *getRoot()
    {
        return root;
    }

    Node *_recursiveInsert(Node *root, Node *n)
    {
        if (root == NULL)
        {
            root = n;
            return root;
        }
        else if (root->prefId > n->prefId)
        {
            root->left = _recursiveInsert(root->left, n);
        }
        else
        {
            root->right = _recursiveInsert(root->right, n);
        }

        return root; // each subtree will return their respective roots.
    }

    void _inOrder(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        _inOrder(root->left);
        cout<<"[ "<<root->prefId<<" ]"<<"\t";
        _inOrder(root->right);
    }

    bool _search(Node* root, int prefuid)
    {
       if(root == NULL) return false;
        if( prefuid == root->prefId) return true;
        else if(prefuid > root->prefId) return _search(root->right, prefuid);
        else return _search(root->left, prefuid);
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
    BinarySearchTree* Tree = new BinarySearchTree();
    Tree->insert(new Node(1, prefObj));
    // Tree->insert(new Node(3, prefObj));
    Tree->insert(new Node(2, prefObj));
    Tree->insert(new Node(5, prefObj));
    Tree->insert(new Node(4, prefObj));
    cout<<"Printing..."<<endl;
    Tree->inOrder();
    // Tree->doCounting();
    getchar();
    

    return 0;
}