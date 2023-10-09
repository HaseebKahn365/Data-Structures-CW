

#include<iostream>
using namespace std;

const int len = 10;

class DEQueue{
    int front = 0;
    int rear = -1;
    int count= 0;
    int Q[len];
    
    public:
    //creating constructor for making all points NULL
    DEQueue(){
        for(int i=0; i<len; i++){
            Q[i]= NULL;
        }
    }

    bool isEmpty(){
        return (count == 0);
    }

    bool isFull(){
        return (count == 9);
    }

    

    void insertFront(int element){
        if(!isFull()){

          if(front==0){
            front =9;
        }
        cout<<element<<" Inserted at left side of the queue"<<" Rear="<<rear<<" \tFront="<<front;
        Q[front --] = element;
        
        count++;
  
        }
        
    }

    void insertRear(int element){

        if(!isFull()){
            if(rear == 9){
            rear = -1;
        }
        cout<<element<< "Inserted at the left side of the queue" <<" Rear="<<rear<<" \tFront="<<front;
        Q[++rear] = element;

        count++;

        }

    }

    void removeRear(){
        if(!isEmpty()){

        
        cout<<"Removed"<<Q[rear];
        Q[rear--]= NULL;

        count--;
        }
        
    }

    void removeFront(){
        if(!isEmpty()){

        if(front==10){
            front =0;
        }
        
        Q[front++]= NULL;

        count--;

        }
       
    }
    void display(){
        for(int i=0; i< len; i++){
            if(i == 0){
            cout<<"Index \t\t Value \t\t Pointer"<<endl;
            }
            cout<<i <<"\t\t";
            cout<<( (Q[i]== NULL)?" empty" : to_string(Q[i]) );
            cout<< "\t\t";
            cout<<(  (rear == i)? " Rear" : "" ); 
            cout<<( (front == i)? " Front" : "" );
            cout<<endl;
        }

    }
};


int main(){
    cout<<"Program started!";
    DEQueue* q = new DEQueue();
    int inputElement;
    bool isRepeat = true;
    int commandNum;

    while(isRepeat){

        cout<<"\nPlease enter a number representing an operation in the following list (-1 to quit): "<<endl;

        cout<<"1. InsertRear()\n2. InsertFront() \n3. RemoveRear() \n4. RemoveFront() \n5. Display() \n";
        cin>>commandNum;

        switch (commandNum)
        {
        case 1:
        cout<<"\n\nEnter a value that you want to insert on the rear: ";
        cin>>inputElement;
            q-> insertRear(inputElement);
            break;

         case 2:
         cout<<"\n\nEnter a value that you want to insert on the front: ";
            cin>>inputElement;
            q-> insertFront(inputElement);
            break;

         case 3:
            q-> removeRear();
            break;
         case 4:
            q-> removeFront();
            break;
         case 5:
            q-> display();
            break;
        
        default:
        isRepeat = false;
            break;
        }
    }
    cout<<"\nProgram has ended";
}

