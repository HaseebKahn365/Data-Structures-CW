#include <iostream>
#include <string>
#include "Prefference.h"

using namespace std;




class HNode{
    public:
    int pref_id;
    Prefference pref;
    HNode* left;
    HNode* right; 

    HNode(int id, Prefference p){
        pref_id = id;
        pref = p;
        left = NULL;
        right = NULL;
    } 

    
};

class HBST{
    HNode* root;

    public:
    HBST(){
        root = NULL;
    }

    void insert(HNode* n){
        if(root == NULL){
            root = n;
        }else{
            HNode* curr = root;
            HNode* parent = NULL;

            while(curr != NULL){
                parent = curr;
                if(n->pref_id < curr->pref_id){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }

            if(n->pref_id < parent->pref_id){
                parent->left = n;
            }else{
                parent->right = n;
            }
        }
    }

    HNode* search(int id){
        HNode* curr = root;

        while(curr != NULL){
            if(curr->pref_id == id){
                return curr;
            }else if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        return NULL;
    }

    void deleteNode(int id){
        HNode* curr = root;
        HNode* parent = NULL;

        while(curr != NULL && curr->pref_id != id){
            parent = curr;
            if(id < curr->pref_id){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        if(curr == NULL){
            return;
        }

        if(curr->left == NULL && curr->right == NULL){
            if(parent == NULL){
                root = NULL;
            }else if(parent->left == curr){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else if(curr->left == NULL){
            if(parent == NULL){
                root = curr->right;
            }else if(parent->left == curr){
                parent->left = curr->right;
            }else{
                parent->right = curr->right;
            }
        }else if(curr->right == NULL){
            if(parent == NULL){
                root = curr->left;
            }else if(parent->left == curr){
                parent->left = curr->left;
            }else{
                parent->right = curr->left;
            }
        }else{
            HNode* succParent = curr;
            HNode* succ = curr->right;

            while(succ->left != NULL){
                succParent = succ;
                succ = succ->left;
            }

            if(succParent != curr){
                succParent->left = succ->right;
            }else{
                succParent->right = succ->right;
            }

            succ->left = curr->left;
            succ->right = curr->right;

            if(parent == NULL){
                root = succ;
            }else if(parent->left == curr){
                parent->left = succ;
            }else{
                parent->right = succ;
            }
        }

        delete curr;
    }

    void inorder(){
        inorder(root);
    }

    void inorder(HNode* node){
        if(node != NULL){
            inorder(node->left);
            cout<<node->pref_id<<" ";
            inorder(node->right);
        }
    }
    
};
