#include<iostream>
using namespace std;
//This is the queue with a moving front;
const int capacity = 5;

class item{
    int age;
    float gpa;
    public:
    item(int a, float g) : age(a), gpa(g) {}
    void display(){
        cout<<"\nItem with age: "<<age <<"gpa: "<<gpa<<endl;
    }
};

class Queue{
    item* arr[capacity];
    int count = 0;
    int front =0;
    int rear =0;

    public:
    bool isFull(){
       return count == capacity;
    }
    bool isEmpty(){
        return count ==0;
    }

    void enqueue(item* i){
        if(isFull()){
            cout<<"Queue Overflow!\n";
        }else{
            cout<<"Item inserted\n";
            count++;
            arr[rear++] = i;
        }
    }

    item* dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return NULL;
        }else{
            count--;
            item* temp = arr[front++];
            if(front == rear){
                cout<<"reseting both front and rear:\n";
                front = rear = 0;
            }
            return temp;
        }

    }

};

int main()
{
    freopen("outputTextFile.txt", "a", stdout);
    Queue* Q = new Queue();

    for(int i=0; i<6; i++){
        Q->enqueue(new item(23+i, 2.5 + (0.2*i)));
    }

    item* removedItem;
    for(int i=0; i<7; i++){
        removedItem = Q -> dequeue();
        if(removedItem != NULL){
            removedItem ->display();
        }
    }
    cout<<"\nProgram has ended!";

    
    return 0;
}