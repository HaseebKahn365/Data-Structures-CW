#include<iostream>
using namespace std;



class item{


    public:
    int data;
    item* next= NULL;
    item(int d): data(d){}

    void display(){
        cout<<"Displaying item with data: "<<data<<endl;
    }


};

class SinglyLinkedList{
    item* head = NULL;
    int count =0;

    public:

    void insertSoted(item* i){
        int key = i->data;
        if(head == NULL || key< head->data){
            i->next = head;
            head = i;
            return;
        }
        item* temp = head;
        while(temp-> next != NULL && temp->next->data < key){
            temp = temp->next;
        }
        i->next = temp->next;
        temp->next = i;
        count++;
    }

    void display(){
        item* temp = head;
        while(temp != NULL){
            temp ->display();
            temp = temp->next;
        }
    }


};


int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();
    list ->insertSoted(new item(23));
    list ->insertSoted(new item(25));
    list ->insertSoted(new item(16));
    list ->insertSoted(new item(12));
    list ->insertSoted(new item(25));
    list ->insertSoted(new item(24));

    list ->display();
    
    return 0;
}