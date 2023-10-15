#include<iostream>
using namespace std;
const int capacity = 5;

class item{
    int age;
    float gpa;
    public:
    item(int a, float g) : age(a), gpa(g) {}
    void display(){
        cout<<"\nItem with age: "<<age <<" and gpa: "<<gpa<<endl;
    }
};

class CircularQueue{
    item* arr[capacity];
    int front = 0;
    int rear = 0;
    int count = 0;

    public:
    bool isFull(){
        return count == capacity;
    }
    
    bool isEmpty(){
        return count == 0;
    }

    void enqueue(item* i){
        if(!isFull()){
            arr[rear] = i;
            rear = ( rear+1 ) % capacity; 
            count++;
            cout<<"Item inserted!\n";
        }else{
            cout<<"Queue overflow!\n";
        }
    }

    item* dequeue(){
        if(!isEmpty()){
            item* temp = arr[front];
            front = (front + 1) % capacity;
            count--;
            return temp;
        }else{
            cout<<"Sorry cannot deque because the queue is empty\n";
            return NULL;
        }
    }



};

int main()
{

     freopen("outputTextFile.txt", "w", stdout);
    CircularQueue* Q = new CircularQueue();

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