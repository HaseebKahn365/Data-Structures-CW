#include<iostream>
using namespace std;

class item{
    public:
    int key;
    char data;
    item* right = NULL;
    item* left = NULL;
    item(int k, char c): key(k), data(c){}
    void display()
    {
        cout<<"Item with key= "<<key<<" and data= "<<data<<endl;
    }

};

class BST{
    item* root = NULL;
    public:
  void insert(item* i) {
    if (root == NULL) {
        cout << "The new item has been made a root element" << endl;
        root = i;
    } else {
        item *parent = NULL;
        item *curr = root;

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


item* search(int key){
    // if(root == NULL) cout<<"Exception: The root is null"<<endl;
    item *parent, *curr;
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
}



    
    

};

int main()
{
    BST *tree = new BST();
    tree->insert(new item(50, 'h'));
    tree->insert(new item(75, 'a'));
    tree->insert(new item(30, 's'));
    tree->insert(new item(45, 's'));
    tree->insert(new item(24, 's'));

    tree->search(45)->display();
    tree->search(24)->display();
    if((tree->search(21)) == NULL){
        cout<<"Nothing found!"<<endl;
    }

    
    return 0;
}