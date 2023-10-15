#include<iostream>
#include<stdlib.h>
using namespace std;
class item{
    int age;
    float gpa;
    public:
    item* next = NULL;
    item(int a, float g) : age(a), gpa(g) {}
    void display(){
        cout<<"Item with age: "<<age <<"and gpa: "<<gpa<<endl;
    }
};

class LinkedListDEQ{
    item* head = NULL;
    item* tail = NULL;
    int count = 0;
    public:
    bool isEmpty(){
        return count == 0;
    }

    void insertFront(item* i) {
        cout << "Item inserted at front\n";
        i->next = head;
        head = i;
        if (tail == nullptr) {
            tail = i;
        }
        count++;
    }

    void insertRear(item* i) {
        cout << "Item inserted at rear\n";
        if (isEmpty()) {
            head = tail = i;
        } else {
            tail->next = i;
            tail = i;
        }
        count++;
    }

    item* removeFront() {
        if (!isEmpty()) {
            item* temp = head;
            head = head->next;
            temp->next = nullptr;
            if (head == nullptr) {
                tail = nullptr; // If the queue is empty after removal, reset the tail.
            }
            count--;
            return temp;
        } else {
            cout << "Sorry, cannot dequeue because the DEQueue is empty\n";
            return nullptr;
        }
    }


item* removeRear() {
    if (!isEmpty()) {
        if (count == 1) {
            item* temp = head;
            head = nullptr;
            tail = nullptr; // Reset the tail
            count--;
            return temp;
        } else {
            item* current = head;
            item* secondLast = nullptr;
            for (int i = 0; i < count - 2; i++) { // Use count - 2 to get the second-to-last item
                current = current->next;
            }
            secondLast = current;
            item* temp = secondLast->next;
            tail = secondLast;
            tail->next = nullptr;
            count--;
            return temp;
        }
    } else {
        return nullptr;
    }
}

    

};

int main(){
    freopen("outputTextFile.txt", "w", stdout);

    LinkedListDEQ* deq = new LinkedListDEQ(); // Create a double-ended queue

    // Insert items at the front and rear
    deq->insertFront(new item(25, 3.5)); // Insert at the front
    deq->insertFront(new item(30, 3.7));
    deq->insertRear(new item(20, 3.2));  // Insert at the rear
    deq->insertRear(new item(28, 3.4));

    // Display the items after insertion
    cout << "Items after insertion:" << endl;
    item* currentItem = deq->removeFront(); // Remove and display items from the front
    while (currentItem != nullptr) {
        currentItem->display();
        currentItem = deq->removeFront();
    }

    deq->insertFront(new item(35, 3.8)); // Insert at the front
    deq->insertRear(new item(22, 3.3));  // Insert at the rear

    // Display the items after more insertion
    cout << "Items after more insertion:" << endl;
    currentItem = deq->removeRear(); // Remove and display items from the rear
    while (currentItem != nullptr) {
        currentItem->display();
        currentItem = deq->removeRear();
    }

    return 0;
}