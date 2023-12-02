#include<iostream>
#include "stack.h"
using namespace std;



class BST{
    Node* root = NULL;
    public:
    Node* getRoot (){
        return root;
    }
  void insert(Node* i) {
    if (root == NULL) {
        cout << "The new Node has been made a root element" << endl;
        root = i;
        return;
    } 
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


        //creating a populateBST to fill the tree with randomly assigned keys;

        void populateBST(int lim){
            int key;
            for(int i=0; i<lim; i++){
                //assign a random key to the key variable;
                key  =  rand()%1000;
                this->insert(new Node(key, 'a'));
            }
        }


    




//tree traversals in BST:
//preorder: root-> left -> right

void preOrder(Node *n){
    if(n == NULL){
        return;
    }
    cout<<n->key<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

//in-order traversal

void inOrder(Node* n, int& counter){
    if(n == NULL) return;
    inOrder(n->left, counter);
    counter++;
    cout<<n->key<<"\t";
    if(counter%10 == 0){
        cout<<endl;
    }
    inOrder(n->right, counter);
}

//post-order traversal:
void postOrder(Node* n){
    if(n==NULL){
        return;
    }
    postOrder(n->right);
    cout<<n->key<<"\t";
    postOrder(n->left);
}

//breadth-first traversal using recursion:
void breadthFirst(Node* n){
    if(n == NULL) return;
    cout<<n->key<<"\t";
    breadthFirst(n->left);
    breadthFirst(n->right);
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
}

Node* searchRecursive(int key, Node* n){
    if(n->key == key){
        return n;
    }
    if(n->key != key && n==NULL) return NULL;
    if(n->key >key){
        n= n->left;
    }else{
        n= n->right;
    }
    
    return searchRecursive(key, n);
}


//creating a method to traverse the BST using Stack from the STL and without recursion:

void inOrderIterative(Node* n){
    
    Node* curr = n;
    int counter =0;
    MyStack stack;

    
    while(curr != NULL || !stack.isEmpty()){

        
        while(curr != NULL){
            //going to the left leaf node and adding all the nodes we face along the way to the MyStack
            stack.pushNode(curr);
            curr = curr->left;
        }
        curr = stack.getTop();
        stack.popNode();
        counter ++;
        cout<<curr->key<<"\t";
        if(counter%20==0){

         cout<<endl;
        }

        curr = curr->right;

    }


}


    
};

int main()
{
    BST *tree = new BST();
  cout<<"Populating the tree with 100 nodes:";

    tree->populateBST(100);

    cout<<"\n Start of the inOrder using iterative method:\n";
    tree->inOrderIterative(tree->getRoot());

    

    


    

    
    return 0;
}