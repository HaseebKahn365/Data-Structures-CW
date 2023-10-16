#include <iostream>
using namespace std;

class item{
public:
    int age;
    float gpa;
    item* Next = NULL;

    void display(){
        cout<<"\nDisplaying: age: "<<age<<" gpa: "<< gpa;
    }

    item(int m, float g){
        age = m;
        gpa = g;
    }
};

class linkedList
{
private:
    item *head;
    item *tail;
    int size;

public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertHead(item *i)
    {
        if (head == NULL)
        {
            head = i;
            tail = i;
        }
        else
        {
            i->Next = head;
            head = i;
        }
        tail->Next = head;
        size++;
    };

    void insertTail(item *i)
    {
        if (head == NULL)
        {
            head = i;
            tail = i;
            tail->Next = head;
        }
        else
        {
            tail->Next = i;
            tail = i;
            i->Next = head;
        }
        size++;
    };

    item *removeHead()
    {
        if (size != 0)
        {
            item *temp = head;
            head = temp->Next;
            tail->Next = head;
            size--;
            return temp;
        }
        else
        {
            cout << "\nThe list is empty! Can't remove head" << endl;
            return NULL;
        }
    }

    item *removeTail()
    {
        if (size != 0)
        {
            item *curr = head, *prev;

            for (int i = 0; i < size - 1; i++)
            {
                prev = curr;
                curr = curr->Next;
            }

            item *temp = curr;
            prev->Next = head;
            delete curr;
            size--;
            return temp;
        }
        else
        {
            cout << "\nThe list is empty! Can't remove tail" << endl;
            return NULL;
        }
    }


    void bubbleSort()
    {
        if (size == 0 || size == 1)
        {
            cout << "List is too small to be sorted!" << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++)
        {
            item *curr = head;
            item *prev = NULL;

            for (int j = 0; j < size - i - 1; j++)
            {
                item *curr_next = curr->Next;

                if (curr->age > curr_next->age)
                {
                    if (prev != NULL)
                        prev->Next = curr_next;
                    else
                        head = curr_next;

                    curr->Next = curr_next->Next;
                    curr_next->Next = curr;

                    if (curr == head)
                        head = curr_next;
                    if (curr_next == tail)
                        tail = curr;
                    prev = curr_next;
                }
                else
                {
                    prev = curr;
                    curr = curr->Next;
                }
            }
        }
        tail->Next = head;
    }

    int listLength()
    {
        cout << "Total length of elements in list is: " << size << endl;
        return size;
    }

    void display()
    {
        item *ptr = head;
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                ptr->display();
                ptr = ptr->Next;
            }
        }
        else
            cout << "\nNothing found in the list to display!" << endl;
    }
};

int main()
{
    linkedList list;
    item *newItem = new item(21, 3.1);

    list.insertTail(newItem);
    newItem= new item(19, 3.2);
    list.insertTail(newItem);
    newItem= new item(17, 3.3);
    list.insertHead(newItem);
    newItem= new item(22, 3.4);
    list.insertTail(newItem);
    newItem= new item(25, 3.5);
    list.insertTail(newItem);
    newItem= new item(24, 3.6);
    list.insertTail(newItem);
    newItem= new item(21, 3.7);
    list.insertHead(newItem);
    newItem= new item(20, 3.8);
    list.insertTail(newItem);
    newItem= new item(15, 3.9);
    list.insertTail(newItem);
    list.listLength();
    cout<<"\nBefore sorting\n";
    list.display();

    list.bubbleSort();
    cout << "\n\nAfter sorting:";
    list.display();
    return 0;
}
