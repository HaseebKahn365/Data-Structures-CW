

//creating the queue class

#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;


public:

    Queue(int s)
    {
        front = 0;
        rear = 0;
        size = s;
        arr = new int[size];
    }

    
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //creating the isFull function
    bool isFull()
    {
        if (rear == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //creating the enqueue function
    void insert(int value)
    {
        cout<<"Inserting the element: "<<endl;
        if(isFull()){
            cout<<"Cannot insert because Queue is full"<<endl;
        }
        else
        {
            arr[rear] = value;
            rear++;
             //showing values of front and rear
            cout << "front: " << front << "rear: "<< rear << endl;
        }
    }

    //creating the deleting function
    int deleting()
    {
       
       if(isEmpty()){
        cout<<"Cannot delete from an empty queue"<<endl;
       }
        else
        {
            
            int temp = *(arr+front);
            
            for (int i = 0; i < rear - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;

            return temp;
            
        }

        
    }

    //display all elements
    void display()
    {
        for (int i = 0; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
   
};


int main(){

    Queue* q1 = new Queue(4);
    int value, option;


    q1->insert(10);
    q1->insert(20);
    q1->insert(30);
    q1->insert(40);
    q1->insert(50);


    cout<<"Deleting value: "<<q1->deleting();
    

    q1->display();

    

    return 0;
}

