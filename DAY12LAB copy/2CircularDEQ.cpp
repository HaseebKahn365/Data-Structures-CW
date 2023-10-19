#include <iostream>
using namespace std;

class item
{
public:
    int data;
    item *next = NULL;
    item *previous = NULL;
    item(int d) : data(d) {}

    void display()
    {
        cout << "Displaying item with data: " << data << endl;
    }
};

class DEQLinkedList
{
    item *head = NULL;
    item *tail = NULL;

    int count = 0;

public:
    void insertFirst(item *i)
    {
        if (head == NULL)
        {
            cout << "First item inserted on front!" << endl;
            head = i;
            tail = i;
            count++;
        }
        else
        {
            cout << "Item inserted on the front!" << endl;
            i->next = head;
            head->previous = i;
            head = i;
            i->previous = tail;
            count++;
        }
    }

    void insertLast(item *i)
    {
        if (tail == NULL)
        {
            // cout << "First item inserted on the rear!" << endl;
            head = i;
            tail = i;
            count++;
        }
        else
        {
            // cout << "item is inserted at the last!" << endl;

            tail->next = i;
            i->previous = tail;
            tail = i;
            i->next = head;

            count++;
        }
    }

    item *removeFirst()
    {
        cout<<"count: "<<count;
        if (count == 0)
        {
            cout << "You have not even inserted any items! Error: 100" << endl;
            return NULL;
        }
        else
        {
            cout << "Removed top!" << endl;
            if (count == 1)
            {
                item *temp = head;
                head = tail = NULL;
                count--;
                return temp;
            }
            else
            {
                item *temp;
                temp = head;
                head = head->next;
                head->previous = tail; // Making the front connect to tail after removal
                count--;
                return temp;
            }
        }
    }

    item *removeLast()
    {
        if (tail == NULL)
        {
            cout << "You have not even inserted any items! Error: 101" << endl;
            return NULL;
        }
        else
        {
            if (count == 1)
            {
                cout << "\nRemoved last!" << endl;
                item *temp = tail;
                head = tail = NULL;
                count--;
                return temp;
            }
            else
            {
                item *temp = tail;
                tail->previous->next = head; // connecting the next of the last item to the head;
                tail->previous = NULL;
                tail->next = NULL; // isolating the item;
                count--;
                return temp;
            }
        }
    }
    void displayAll()
    {
        item *temp = tail;

        for (int i = 0; i < count; i++)
        {
            temp->display();
            temp = temp->previous;
        }
    }

    void printState()
    {
        cout << "\n<-------Printing the state of the DEQ-----> \nHead: " << head << endl;
        cout << "Tail: " << tail << endl;
        cout << "Count: " << count << "\n\n";
    }

    item *searchItem(int d)
    {
        item *curr = head;
        for (int i = 0; i < count; i++)
        {
            if (curr->data == d)
            {
                cout << "\n\nItem found: \n";
                return curr;
            }
        }
    }

    void searchMultiple(int d)
    {
        DEQLinkedList *foundItems = new DEQLinkedList();
        item *curr = head;
        for (int i = 0; i < count; i++)
        {
            
            if (curr->data == d)
            {
                item *temp = new item(curr->data);
                cout << "found it\n\n";

                foundItems->insertLast(temp);
            }
            curr = curr->next;
        }

        cout << "Total found items = " << foundItems->count << endl;
        foundItems->displayAll();
    }
};

int main()
{
    freopen("out.txt", "w", stdout);
    cout << "This is the Start of the program:" << endl;
    DEQLinkedList *DEQ = new DEQLinkedList();
    // DEQ->printState();
    // DEQ->insertFirst(new item(21));
    // DEQ->printState();
    // DEQ->insertFirst(new item(22));
    // DEQ->printState();
    // DEQ->insertFirst(new item(23));
    // DEQ->printState();
    // DEQ->removeFirst()->display();
    // DEQ->printState();
    // DEQ->removeFirst()->display();
    // DEQ->printState();
    // DEQ->removeFirst()->display();
    // DEQ->removeFirst()->display();
    // test 2:
    DEQ->insertLast(new item(23));
    DEQ->printState();
    DEQ->removeLast();
    DEQ->printState();

    // test3: display test:

    DEQ->insertFirst(new item(21));
    DEQ->printState();
    DEQ->insertFirst(new item(22));
    DEQ->printState();
    DEQ->insertFirst(new item(23));
    DEQ->insertFirst(new item(23));
    DEQ->insertFirst(new item(23));
    DEQ->insertFirst(new item(23));
    DEQ->insertFirst(new item(23));
    DEQ->insertFirst(new item(23));
    DEQ->printState();
    DEQ->displayAll();

    // DEQ->searchItem(23)->display();
    cout << "\n\nSearching for mulitple 23\n\n";
    DEQ->searchMultiple(23);
    cout << "\n\n\nThe program has ended\n\n this is the new output\n";
    return 0;
}