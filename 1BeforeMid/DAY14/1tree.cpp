#include<iostream>
using namespace std;

class item{

    public: 
    int data;
    item* right = NULL;
    item* left = NULL;
    item(int d): data(d){}
    void display(){
        cout<<"\nItem with data: "<<data<<endl;
    }

};

class tree{
    item* root = NULL;

    public:
    int count = 0;
    void insert(item* i){
        if(root == NULL){
            cout<<"Inserting the element on the head of the tree\n";
            root = i;
            count++;
            return;
        }
        item* temp = root;
        bool broken = false;
        while(!broken){
            // code for dart: 
            //(i->data > temp->data && temp->right != NULL)? (){temp = temp->rigth} : (temp -> right= NULL)? (){temp->right = i}: (){};
            
            if(i->data > temp->data){
                broken = (temp->right == NULL)? true: false;
                if(broken) {
                cout<<"trying to insert on the right\n";
                    count ++;
                    temp->right = i;
                     return;
                } 
                    temp = temp->right;
            }else{
                broken = (temp->left == NULL)? true: false;
                if(broken) {
                cout<<"Trying to insert on the left\n";
                count ++;
                    temp->left = i;
                     return;
                } 
                    temp = temp->left;
            }
        }
    }

};



int main()
{
    tree* newtree = new tree();
    //avoid entering the same keys;
    newtree -> insert(new item(23));
    newtree -> insert(new item(24));
        newtree -> insert(new item(67));
    newtree -> insert(new item(10));
    newtree -> insert(new item(32));

    newtree -> insert(new item(13));
    newtree -> insert(new item(36));
    newtree -> insert(new item(42));
    cout<<"\nNo. of items in the tree = "<<newtree->tree::count;
}