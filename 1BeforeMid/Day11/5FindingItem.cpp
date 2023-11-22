#include<iostream>
using namespace std;

class item{
    public:
    int age;
    float gpa;
    item* Next = NULL;

    void display(){
        cout<<"\nDisplaying: age: "<<age<<" gpa: "<< gpa;
    }

    item(int m, float g){
        age = m;
        gpa = g;
    }
};

class linkedList{
    item* head = NULL;
    int count =0;

    public:
    
    void insertFirst(item* i){
        cout<<"Inserting no."<<count+1<<" Item: \n";

        if(head == NULL){

            head = i;
            count++;

        }else{

           i -> Next = head;
           head = i;
           count++;

        }
    }
    

    item* remove(){

        if(head == NULL){
            count--;

            return NULL;

        }else{
            
            item* current = head;

            head = head -> Next;
            count--;

            return current;

        }

    }
    int showSize(){
        return count;
    }

    void displayAll(){
        item* temp = head;
        while(temp != NULL){
            temp -> display();
            temp= temp -> Next;
        }
    }

    item* FindN(int n){
        item* temp = head;
        while(temp != NULL){
            if(temp -> age == n){
                cout<<"The item has been found:\n";
                return temp;
            }
            temp= temp -> Next;
        }
    }

};

int main()
{
    freopen("out.txt","w", stdout);
     linkedList* myList = new linkedList();
   myList->insertFirst(new item(23, 3.5));
     myList->insertFirst(new item(24, 3.5));
      myList->insertFirst(new item(25, 3.5));
      myList->insertFirst(new item(27, 3.5));
      myList->insertFirst(new item(25, 3.8));

    myList -> FindN(25) ->display();
    cout<<"\nProgram ended";

    
    
 
    return 0;
}