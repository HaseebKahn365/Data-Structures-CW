


#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class item
{

    float gpa;

public:
    item *Next = NULL;

    void display()
    {
        cout << "\nDisplaying gpa: " << gpa << endl;
    }

    item(float g)
    {

        gpa = g;
    }
};

class linkedList
{
    item *head = NULL;

public:
    void insertLast(item *i)
    {

        if (head == NULL)
        {
            head = i;
            return;
        }
        item *curr = head;

        while (curr != NULL)
        {
            if (curr->Next == NULL)
            {
                curr->Next = i;
                return;
            }
            curr = curr->Next;
        }
    }

    // create  a method that clears all the list items
    void clearList()
    {
        item *curr = head;
        while (curr != NULL)
        {
            item *temp = curr;
            curr = curr->Next;
            delete temp;
        }
        head = NULL;
    }
};

void testInsertionAtTail(linkedList *myList)
{
    // inserting 5 random elements and recording the time

    auto start_time = high_resolution_clock::now();
    for (int i = 0; i < 5; i++)
    {
        item *newItem = new item(rand() % 4);
        myList->insertLast(newItem);
    }

    auto end_time = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << duration.count() << std::endl;

    // clearing the list
    myList->clearList();

    // similarly running the test for 20 items

    start_time = high_resolution_clock::now();
    for (int i = 0; i < 20; i++)
    {
        item *newItem = new item(rand() % 4);
        myList->insertLast(newItem);
    }

    end_time = high_resolution_clock::now();
    
    duration = duration_cast<microseconds>(end_time - start_time);
    cout << duration.count() << std::endl;

    myList->clearList();
    
    // similarly running the test for 50 items

    start_time = high_resolution_clock::now();
    for (int i = 0; i < 50; i++)
    {
        item *newItem = new item(rand() % 4);
        myList->insertLast(newItem);
    }

    end_time = high_resolution_clock::now();
    
    duration = duration_cast<microseconds>(end_time - start_time);
    cout << duration.count() << std::endl;

    myList->clearList();
    // similarly running the test for 100 items

    start_time = high_resolution_clock::now();
    for (int i = 0; i < 100; i++)
    {
        item *newItem = new item(rand() % 4);
        myList->insertLast(newItem);
    }

    end_time = high_resolution_clock::now();
    
    duration = duration_cast<microseconds>(end_time - start_time);
    cout << duration.count() << std::endl;

    myList->clearList();
    // similarly running the test for 1000 items

    start_time = high_resolution_clock::now();
    for (int i = 0; i < 1000; i++)
    {
        item *newItem = new item(rand() % 4);
        myList->insertLast(newItem);
    }

    end_time = high_resolution_clock::now();
    
    duration = duration_cast<microseconds>(end_time - start_time);

    cout << duration.count() << std::endl;
}

int main()
{
    linkedList *myList = new linkedList();

  
    cout << "Inserting elements in the list without the tail for 5, 20, 50, 100, 1000 items in the list" << endl;

    testInsertionAtTail(myList);

    return 0;
}