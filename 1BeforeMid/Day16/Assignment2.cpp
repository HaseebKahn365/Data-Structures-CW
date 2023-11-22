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
    public:
    int count = 0;
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
        }else{
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

    // void printStoreState(){
    //     cout<<"Line 1 wieght: "<<line1->weight<<endl;
    //     cout<<"Line 2 wieght: "<<line2->weight<<endl;
    //     cout<<"Line 3 wieght: "<<line3->weight<<endl;

    // }

    int calculateMinLine(){
       if(line1->weight<= line2->weight && line1->weight<= line3->weight) {return 1;}
        else if(line2->weight<=line1->weight && line2->weight <= line3->weight) {return 2;}
        else{ return 3;};
    }


    void JoinALine(Customer* i){
        // printStoreState();
        int bestLine = calculateMinLine();
        // cout<<"The best line is: "<<bestLine<<endl;

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
        cout<<"\n[burden: "<<line1->weight<<"]Customer Line 1: "; 
        line1->displayAll();
        cout<<endl;

        cout<<"\n[burden: "<<line2->weight<<"]Customer Line 2: "; 
        line2->displayAll();
        cout<<endl;

        cout<<"\n[burden: "<<line3->weight<<"]Customer Line 3: "; 
        line3->displayAll();
        cout<<endl;

    }



    //!----------> CheckoutCustomers <---------!// --------->
    //TODO:it will remove the first three customers from each line respectively
    void checkOutCustomers(){
        if(line1->weight !=0)line1->removeFirst();
        if(line2->weight !=0)line2->removeFirst();
        if(line3->weight !=0)line3->removeFirst();
    }

};




int main()
{
    Store s1;

    int opCode;
    do{
        cout<<"\n\nPlease enter one of the following operations:\n";
        cout<<"1)Join a Line\n";
        cout<<"2)Look/Peek at all Lines\n";
        cout<<"3)Checkout customers\n";
        cout<<"You entered: "; cin>>opCode;

        switch (opCode)
        {
        case 1:
            cout<<"\nEnter customer id: ";
            int id; cin>>id;
            cout<<"Enter no. of items: ";
            int items; cin>>items;
            s1.JoinALine(new Customer(id, items));
            cout<<"Person added!\n";
            break;
        
        case 2:
            cout<<"\nPeeking at store: \n";
            s1.peekLines();
            break;
        case 3:
            cout<<"\nChecking out customers\n";
            s1.checkOutCustomers();

            break;
        
        default:
            cout<<"The Store application has ended! Bye\n\n";
            cout<<"\nTHis is the end";
            exit(0);
            break;
        }

    }while(opCode!=0);


    return 0;
}