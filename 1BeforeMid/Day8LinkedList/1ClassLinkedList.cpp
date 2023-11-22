#include<iostream>
using namespace std;

class item{
    int marks;
    float gpa;
    public:
    item* Next = NULL;

    void display(){
        cout<<"\nDisplaying: Marks: "<<marks<<" gpa: "<< gpa;
    }

    item(int m, float g){
        marks = m;
        gpa = g;
    }
};

class linkedList{
    item* head = NULL;

    public:
    
    void insertFirst(item* i){

        if(head == NULL){

            head = i;

        }else{

           i -> Next = head;
           head = i;

        }
    }
    

    item* remove(){

        if(head == NULL){

            return NULL;

        }else{
            
            item* current = head;

            head = head -> Next;

            return current;

        }

    }
};

int main()
{
    linkedList* myList = new linkedList();

    myList->insertFirst(new item(23, 3.5));
     myList->insertFirst(new item(24, 3.5));
      myList->insertFirst(new item(25, 3.5));

      myList -> remove() ->display();
      myList->remove()-> display();
    
    myList->remove()->display();
    
    return 0;
}