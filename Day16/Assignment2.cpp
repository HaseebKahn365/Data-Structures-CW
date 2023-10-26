#include<iostream>
using namespace std;

class Customer{
    int id;

    public:
    int items;
    Customer* next= NULL;
    Customer(int d, int i): id(d), items(i){}

    void display(){
        cout<<id<<"  ";
    }



};


class SinglyLinkedList{
    Customer* head= NULL;
    Customer* tail= NULL;
    int count = 0;
    public:
    int weight = 0;



    void insertLast(Customer* i){
        if(head == NULL || tail == NULL){
            head = tail = i;
            count++;
            weight +=i->items;
        }else{
            tail->next = i;
            tail = i;
            count++;
            weight +=i->items;

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
            weight -= temp->items;
            delete temp;
           
        }
    }

    void displayAll(){
        if(head!=NULL){
        Customer* curr= head; 
        curr->display();

        while(curr->next != NULL){
            curr= curr->next;
            curr->display();
            
        } 
        }else{
            cout<<"Empty "<<endl;
        }
       
    }

    void printState(){
        cout<<"\n<-------Printing the state of the DEQ-----> \nHead: "<<head<<endl;
        cout<<"Tail: "<<tail<<endl;
        cout<<"Count: "<<count<<"\n\n";
        cout<<"Total weight: "<<weight<<"\n\n";

    }
};



class Store{
    SinglyLinkedList* line1 = new SinglyLinkedList();
    SinglyLinkedList* line2 = new SinglyLinkedList();
    SinglyLinkedList* line3 = new SinglyLinkedList();
    public:

    void printStoreState(){
        cout<<"Line 1 wieght: "<<line1->weight<<endl;
        cout<<"Line 2 wieght: "<<line2->weight<<endl;
        cout<<"Line 3 wieght: "<<line3->weight<<endl;

    }

    int calculateMinLine(){
       if(line1->weight<= line2->weight && line1->weight<= line3->weight) {return 1;}
        else if(line2->weight<=line1->weight && line2->weight <= line3->weight) {return 2;}
        else{ return 3;};
    }


    void JoinALine(Customer* i){
        printStoreState();
        int bestLine = calculateMinLine();
        cout<<"The best line is: "<<bestLine<<endl;

        switch (bestLine)
        {
        case 1 :
        line1 -> insertLast(i);
        break;

        case 2 :
        line2 -> insertLast(i);
        break;

        case 3 :
        line3 -> insertLast(i);
        break;
        
        default:
        cout<<"Something went wrong in choosing the best line";
            break;
        }
    }

    //!----------> PeekLines <---------!// 
    //TODO:it will only show the statuses of the lines

    void peekLines(){
        cout<<"\nCustomer Line 1: "; 
        line1->displayAll();
        cout<<endl;

        cout<<"\nCustomer Line 2: "; 
        line2->displayAll();
        cout<<endl;

        cout<<"\nCustomer Line 3: "; 
        line3->displayAll();
        cout<<endl;

    }



    //!----------> CheckoutCustomers <---------!// --------->
    //TODO:it will remove the first three customers from each line respectively
    void checkOutCustomers(){
        line1->removeFirst();
        line2->removeFirst();
        line3->removeFirst();
    }

};




int main()
{
    Store s1;
    s1.JoinALine(new Customer(21, 10));
    s1.JoinALine(new Customer(22, 10));
    s1.JoinALine(new Customer(23, 10));
    s1.JoinALine(new Customer(27, 10));
    s1.JoinALine(new Customer(29, 100));

    s1.peekLines();
    s1.checkOutCustomers();
    s1.peekLines();



    return 0;
}