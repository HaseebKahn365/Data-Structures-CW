#include <iostream>
using namespace std;

class item
{
public:
    int age;
    float gpa;
    item *next;

public:
    item(int a, float g)
    {
        age = a;
        gpa = g;
    }

    void display()
    {
        cout << "\nAge = " << age << " GPA = " << gpa<<endl;
    }
};

class LinkedListQueue
{
private:
    item *front = NULL;
    item *rear = NULL;
    int count = 0;

public:
    void insertFirst(item *i)
    {

        if (front == NULL)
        {
            front = i;
            rear = i;
            count++;
            cout << "Item inserted! Total items = " << count << endl;
        }
        else
        {
            item *cur = front;
            front = i;
            i->next = cur;

            count++;
            cout << "Item inserted! Total items = " << count << endl;
        }
    }

    item *removeRear()
    {
        if (rear == NULL)
        {
            cout << "\nSorry! No items found to return!\n";
            return NULL;
        }
        else
        {
            count--;
            cout << "Item deleted! Total items = " << count << endl;

            item *cur = front;
            item *prev = NULL;

            while (cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }

            if (prev != NULL)
            {
                prev->next = NULL; 
            }
            else
            {
                front = NULL; 
            }

            rear = prev; 
            return cur;
        }
    }
};

int main()
{
    LinkedListQueue *Qlinkedlist = new (LinkedListQueue);

    Qlinkedlist->insertFirst(new item(21, 3.3));
    Qlinkedlist->insertFirst(new item(22, 4.0));
    Qlinkedlist->removeRear()->display();
    Qlinkedlist->removeRear()->display();

    return 0;
}