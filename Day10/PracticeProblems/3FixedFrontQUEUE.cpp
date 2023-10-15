#include<iostream>
using namespace std;

const int capacity = 5;
class item{
    int age;
    float gpa;

    public:

    item(int a, int g){
        age = a;
        gpa = g;
    }

    void displayItem(){
        cout<<" Displaying item: Age = "<<age <<" GPA = "<< gpa<<endl;
    }
    
};


class Queue{
    int front = 0;
    int rear = -1;

    item* arr[capacity];
    
    public:

    void enqueue(item* i){
        if(rear == capacity-1){
            cout<<"\nSorry the Queue has been filled!\n";
        }else{ 
            cout<<"Item added";
            i->displayItem();
            arr[++rear] = i;
        }
    }

    item* dequeue(){
        if(rear == -1){
            cout<<"\nQueue is empty!\n";
            return NULL;
        }else{
            item* temp = arr[front];
            for(int i=0; i<rear; i++){
                arr[i] = arr[i+1];
            }
            rear--;
            return temp;
        }
    }

    bool isEmpty(){
        return rear == -1;
    }

};

int main()
{

    freopen("outputTextFile.txt","w", stdout);
    Queue* Q = new Queue();
    Q -> enqueue (new item(24, 2.13));
    Q -> enqueue (new item(25, 2.13));
    Q -> enqueue (new item(26, 2.13));
    Q -> enqueue (new item(27, 2.13));

    for(int i = 0; i<5; i++){            
        if( !Q-> isEmpty() ){
            Q -> dequeue() -> displayItem();
        }
    }
    
    
    return 0;
}