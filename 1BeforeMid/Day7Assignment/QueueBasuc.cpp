#include <iostream>

using namespace std;

const int len = 7;

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
    int front = 0;
    int rear = -1;
    int count = 0;
    item *Q[len];

public:
    void enqueue(item *it)
    {
        if (count < len)
        {
            if (rear == len - 1)
            {
                rear == -1;
            }
            Q[++rear] = it;
            count++;
          
        }
        else
        {
            cout << "Queue Overflow!";
        }
    }

    item *dequeue()
    {
        if (count > 0)
        {
            count--;
            item *temp = Q[front++];
              if (front > len)
            {
                front = 0;
            }
            return temp;
        } else {
            return nullptr;
        }
    }
};

int main()
{

    Queue *newQueue = new Queue();

    newQueue->enqueue(new item(23));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->enqueue(new item(25));
    newQueue->dequeue()->show();
    newQueue->dequeue()->show();
    newQueue->dequeue()->show();
}