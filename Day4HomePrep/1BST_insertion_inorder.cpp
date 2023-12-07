#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data = 21;
    Node* right = NULL;
    Node* left = NULL;

    Node(int k){
        key = k;
    }
    
};
class BST{
    Node* root = NULL;

public:
    Node* insert(int key, Node* root){
        if(root == NULL){
            root = new Node(key);
            return root;
        }
        else if(root->key > key){
            root->left= insert(key, root->left);
        }else{
            root->right = insert(key, root->right);
        }
        return root;
    }

    void inorder(Node* root){
        if(root==NULL) return;
        
        inorder(root->left);
        cout<<root->key<<"\t"; 
        inorder(root->right);
    }


    bool search(Node* root, int key){

        if(root == NULL) return false;
        if(root->key == key){
            return true;
        }
        if(root->key> key){
            return search(root->left, key);
        }
        if(root->key<key){
            return search(root->right, key);
        }
        return false;
    }

    Node* deleteNode(Node* root, int key){
        if(root->key > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->key < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            //if root->key == key:
            //case 1: leaf node deletion
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            
            //case 2: if root with one child
            if(root->right == NULL){
                return root->left;
            }
            if(root->left == NULL){
                return root->right;
            }

            //case3: if root with with two children
            Node* IS = inOrderSucessorFinder(root->right);

            //copy the data from the inorder successor to the root;
            root -> key = IS ->key;
            root ->data = IS ->data;

            //delete the IS from the bottom
            root -> right = deleteNode(root->right, IS->key);
        }
        return root;
    }

    Node* inOrderSucessorFinder(Node* succ){
        while(succ->left != NULL){
            succ = succ->left;
        }
        return succ;
    }




};
int main()
{
    int values[6] = {5,1,7,3,2,4};
    Node* newroot = NULL;
    BST* myBST = new BST();

    for(int i=0; i<6; i++){
        newroot = myBST->insert(values[i], newroot);
    }

    myBST->inorder(newroot);
    // cout<<"\n"<<myBST->search(newroot, 1)<<endl;
    cout<<endl;

    newroot = myBST->deleteNode(newroot, 5);
    myBST->inorder(newroot);
    


    
    return 0;
}