#include<iostream>
using namespace std;

const int capacity =5;
class item
{
    int data;
public:
    item(int d) : data(d) {}

    void display()
    {
        cout << "Displaying item with data: " << data << endl;
    }
};

class Queue{
    int front= -1;
    int rear= -1;

    item* arr[capacity];
    public:

    bool isFull(){
        return rear == capacity-1;
    }

    bool isEmpty(){
        return front == -1;
    }
    
    void enqueue(item* i){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;
        }else if(isEmpty()){
            rear = front = 0;
            arr[rear] = i;
        }
       
        else{
            arr[++rear] = i;
        }
    }

    item* dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return NULL;
        }else if(rear == front){
            item* ptr = arr[front];
            rear =  front = -1;    
            return ptr;        
        }else{
            return arr[front++];
        }
    }


};

int main()
{
    freopen("out.txt", "w", stdout);
    Queue* newQ = new Queue();

    newQ -> enqueue(new item(25));
    newQ -> enqueue(new item(26));
    newQ -> enqueue(new item(27));
    newQ -> enqueue(new item(28));
    newQ -> enqueue(new item(29));
    newQ -> enqueue(new item(30));
    
    newQ-> dequeue()->display();
    newQ-> dequeue()->display();
    newQ-> dequeue()->display();
    newQ-> dequeue()->display();
    newQ-> dequeue()->display();

    item* temp = newQ-> dequeue();
    if(temp == NULL){
        cout<<"Invalid Dequeue";
    }



    
    return 0;
}