#include <iostream>

using namespace std;

const int len = 3;

class item
{
    int num = 0;

public:
    item(int n)
    {
        num = n;
    }
    void show()
    {
        cout << "item has int = " << num << endl;
    }
};
class Queue
{
    int front = -1;
    int rear = -1;
    item *Q[len];

public:
    void enqueue(item *it)
    {
        if ((rear + 1) % len == front)
        {
            cout << "\nQueue overflow";
        }
        else
        { 
            rear = (rear + 1) % len;
            Q[rear] = it;
            cout<<"Inserted at rear: "<<rear<<endl;
        }
    }

    item *dequeue()
    {
        if (front == rear)
        {
            cout << "The Queue is empty so cannot dequeue\n";
            return NULL;
        }
        else
        {
        front = (front + 1) % len;
            return Q[front];
        }
    }
};

int main()
{

    Queue *newQueue = new Queue();

    newQueue->enqueue(new item(23));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(26));
    newQueue->enqueue(new item(26));
    newQueue->enqueue(new item(26));
    newQueue->enqueue(new item(27));
    newQueue->enqueue(new item(27));
    newQueue->enqueue(new item(27));
    newQueue->enqueue(new item(28));
    newQueue->enqueue(new item(28));
    newQueue->dequeue()->show();
    newQueue->dequeue()->show();
    newQueue->dequeue()->show();
}