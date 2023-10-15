#include<iostream>
using namespace std;
const int capacity = 5;
//there should not be a limited sized linked
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
    item* arr[capacity];
    item* head= NULL;
    int count=0;
    public:

    bool isEmpty(){
        return count==0;
    }
    bool isFull(){
        return count==capacity;
    }

    void insertFirst(item* i){
        if(isFull()){
            cout<<"Linked list overload!\n";
        }else{
            cout<<"inserting at count: "<<count<<endl;
            i->next = head;
            head = i;
            count ++;
        }
    }

    item* removeFirst(){
        if(isEmpty()){
            cout<<"Empty list!\n";
            return NULL;
        }else{
            item* temp = head;
            head = head -> next;
            count--;
            return temp;
        }
    }
    
};

int main()
{
    freopen("outputTextFile.txt", "w", stdout);
    LinkedList* list = new LinkedList();
    
    for(int i=0; i<6; i++){
        list -> insertFirst (new item(23+i, 2+(0.3 * i)));
    }

    item* removedItem;
    for(int i=0; i<6; i++){
        removedItem = list -> removeFirst();
        if(removedItem != NULL){
            removedItem ->display();
        }
    }
    
    
    return 0;
}