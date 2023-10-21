#include<iostream>
using namespace std;

class item{

    int data;

    public:
    item* next= NULL;
    item* previous = NULL;
    item(int d): data(d){}

    void display(){
        cout<<"Displaying item with data: "<<data<<endl;
    }


};

class DEQLinkedList{
    item* head= NULL;
    item* tail= NULL;
    int count = 0;
    public:

    void insertFirst(item* i){
        if(head == NULL){ cout<<"First item inserted on front!"<<endl;
            head = i;
            tail = i;
            count++;
        }else{cout<<"Item inserted on the front!"<<endl;
            i->next = head;
            head->previous = i;
            head = i;
            count++;
        }
    }

    void insertLast(item* i){
        if(tail== NULL){cout<<"First item inserted on the rear!"<<endl;
            head = i;
            tail = i;
            count++;
        }else{cout<<"item is inserted at the last!"<<endl;
            tail->next = i;
            i->previous = tail;
            tail = i;
            count++;
        }
    }

    item* removeFirst(){
        if(count == 0){
            cout<<"You have not even inserted any items! Error: 100"<<endl;
            return NULL;
        }else{cout<<"Removed top!"<<endl;
            item* temp;
            temp= head;
            head = head->next;
            head->previous = NULL; //Making the front null after removal
            count--;
            return temp;
        }
    }

   item* removeLast() {
        if (tail == NULL) {
            cout << "You have not even inserted any items! Error: 101" << endl;
            return NULL;
        }
        else {
            cout << "\nRemoved last!" << endl;
            item* temp = tail;
            if (tail->previous != NULL) {
                tail->previous->next = NULL;
            }
            else {
                head = NULL; // If the list is empty after removal make the head null
            }
            tail = temp->previous;
            count--;
            return temp;
        }
    }
    void displayAll(){
        if(head!=NULL){
        item* curr= head; int i=1;
                    cout<<"item no. 1"<<endl;
        curr->display();

        while(curr->next != NULL){
            curr= curr->next;
            cout<<"item no. "<<i+1<<endl;
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
    freopen("out.txt", "w", stdout);
    cout<<"This is the Start of the program:"<<endl;
    DEQLinkedList* DEQ = new DEQLinkedList();
    DEQ->printState();
    DEQ->insertFirst(new item(21));
    DEQ->printState();
    DEQ->insertLast(new item(25));
    DEQ->printState();
    DEQ->removeLast()->display();
    DEQ->printState();
    DEQ->removeLast()->display();
    DEQ->printState();
    DEQ->removeFirst();
    DEQ->printState();
    DEQ->insertFirst(new item(31));
    DEQ->insertFirst(new item(32));
    DEQ->insertFirst(new item(34));
    DEQ->insertFirst(new item(36));

    DEQ->displayAll();
    DEQ->printState();
    DEQ->displayAll();

    return 0;
}