#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    char data;
    Node* right = NULL;
    Node* left = NULL;
    Node(int k, char c): key(k), data(c){}
    void display()
    {
        cout<<"Node with key= "<<key<<" and data= "<<data<<endl;
    }

};

class BST{
    Node* root = NULL;
    public:
  void insert(Node* i) {
    if (root == NULL) {
        cout << "The new Node has been made a root element" << endl;
        root = i;
    } else {
        Node *parent = NULL;
        Node *curr = root;

        while (1) {
            parent = curr;

            if (curr->key == i->key) {
                cout << "Invalid value! There can't be repeated keys" << endl;
                return;
            }

            if (curr->key > i->key) {
                cout << "Going to the left of " << curr->key << endl;
                curr = curr->left;

                if (curr == NULL) {
                    parent->left = i;
                    cout << "Inserted at the left of " << parent->key << endl;
                    return;
                }
            } else {
                cout << "Going to the right of " << curr->key << endl;
                curr = curr->right;

                if (curr == NULL) {
                    parent->right = i;
                    cout << "Inserted at the right of " << parent->key << endl;
                    return;
                }
            }
        }
    }
}


Node* search(int key){
    // if(root == NULL) cout<<"Exception: The root is null"<<endl;
    Node *parent, *curr;
    parent = curr = root;
    
    while(1){
        if(curr == NULL) return NULL;
        if(curr->key == key){
            cout<<"The key has been found"<<endl;
            return curr;
        }
        
        if(curr->key > key){
            //look on the left side;
            // if(curr = NULL) return NULL;
            curr = curr->left;
        }
        else if( curr->key < key)
        {
            //look on the right side:
            // if(curr == NULL) return NULL;
            curr = curr-> right;
        }
    }

    //implement the deletion of node using a key passed as a parameter. first look for the empty tree case. then establish the case for leaf node deletion then
    //then for node with single child 
    //then for node with two children use boolean isLeft flag to identify the right or left 

    void delete(Node*)

    

}



    
    

};

int main()
{
    BST *tree = new BST();
    tree->insert(new Node(50, 'h'));
    tree->insert(new Node(75, 'a'));
    tree->insert(new Node(30, 's'));
    tree->insert(new Node(45, 's'));
    tree->insert(new Node(24, 's'));

    tree->search(45)->display();
    tree->search(24)->display();
    if((tree->search(21)) == NULL){
        cout<<"Nothing found!"<<endl;
    }

    
    return 0;
}