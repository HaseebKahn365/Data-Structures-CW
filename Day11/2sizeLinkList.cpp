#include<iostream>
using namespace std;

class item{
    int age;
    float gpa;
    public:
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
};

int main()
{
    freopen("out.txt","w", stdout);

    linkedList* myList = new linkedList();

    myList->insertFirst(new item(23, 3.5));
     myList->insertFirst(new item(24, 3.5));
      myList->insertFirst(new item(25, 3.5));
      myList->insertFirst(new item(25, 3.5));
      myList->insertFirst(new item(25, 3.5));
    
    cout<<"\nThe size of the list is: "<<myList->showSize();
    
    return 0;
}