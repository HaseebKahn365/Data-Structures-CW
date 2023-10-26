#include<iostream>
using namespace std;

class Customer{
    int items;
    int id;

    public:
    Customer* next= NULL;
    Customer(int d, int i): id(d), items(i){}

    void display(){
        cout<<"Customer with id: "<<id<<endl;
        cout<<"items : "<<items<<endl;
    }



};

class SinglyLinkedList{
    Customer* head= NULL;
    Customer* tail= NULL;
    int count = 0;
    public:



    void insertLast(Customer* i){
        if(head == NULL || tail == NULL){
            head = tail = i;
            count++;
        }else{
            tail->next = i;
            tail = i;
            count++;
        }
    }

    void removeFirst(){
        if(count == 0){
            cout<<"You have not even inserted any Customers! Error: 100"<<endl;
        }else{cout<<"Removed top!"<<endl;
            Customer* temp;
            temp= head;
            head = head->next;
            count--;
            delete temp;
           
        }
    }

    void displayAll(){
        if(head!=NULL){
        Customer* curr= head; int i=1;
                    cout<<"Customer no. 1"<<endl;
        curr->display();

        while(curr->next != NULL){
            curr= curr->next;
            cout<<"Customer no. "<<i+1<<endl;
            curr->display();
            i++;
        } 
        }else{
            cout<<"\nCannot display data of an empty list\n";
        }
       
    }

    void printState(){
        cout<<"\n<-------Printing the state of the DEQ-----> \nHead: "<<head<<endl;
        cout<<"Tail: "<<tail<<endl;
        cout<<"Count: "<<count<<"\n\n";
    }
};


int main()
{
    // freopen("out.txt", "w", stdout);
    SinglyLinkedList* list = new SinglyLinkedList();

    list->insertLast(new Customer(1, 23));
    list->printState();
    list->insertLast(new Customer(2, 12));
    list->insertLast(new Customer(3, 15));
    list->insertLast(new Customer(4, 13));
    list->removeFirst();

    list->printState();

    list->displayAll();

    
    return 0;
}