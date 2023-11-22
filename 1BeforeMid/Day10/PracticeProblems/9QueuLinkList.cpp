#include<iostream>
using namespace std;

const int capacity = 5;

class item{
    int age;
    float gpa;
    public:
    item* next = NULL;
    item(int a, float g) : age(a), gpa(g) {}
    void display(){
        cout<<"\nItem with age: "<<age <<"gpa: "<<gpa<<endl;
    }
};

class LinkedList{
    int count=0;
    item* head = NULL;
    item* tail = NULL;

    public:

    void insertRear(item* i){
        if(count == 0){
            head = i;
            tail = i;
            count++;
            cout<<"First item inserted in the queue list \n";
        }else{
            tail -> next = i;
            tail = i;
            count++;
        }
    }

    item* removeFirst(){
        if(count != 0){
            item* temp = head;
            head = head -> next;
            count--;
            temp -> next = NULL; //just playing safe here;
            return temp;
        }else{
            cout<<"Sorry! The queue list is empty!"<<endl;
            return NULL;
        }
    }
};


int main()
{
    freopen("outputTextFile.txt", "w", stdout);
    LinkedList* Q = new LinkedList();
    
     for(int i=0; i<6; i++){
        Q -> insertRear (new item(23+i, 2+(0.3 * i)));
    }

     item* removedItem;
    for(int i=0; i<7; i++){
        removedItem = Q -> removeFirst();
        if(removedItem != NULL){
            removedItem ->display();
        }
    }
    cout<<"\nProgram has ended!";
    
    return 0;
}