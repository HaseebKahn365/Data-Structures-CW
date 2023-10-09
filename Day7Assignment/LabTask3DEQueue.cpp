#include<iostream>
using namespace std;

const int len = 10;

class DEQueue {
    int front = 0;
    int rear = -1;
    int count = 0;
    int Q[len];

public:
    DEQueue() {
        for (int i = 0; i < len; i++) {
            Q[i] = NULL;
        }
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == 10);
    }

    void insertFront(int element) {
        if (!isFull()) {
            if (front == 0) {
                front = len - 1;
            }
            cout << element << " Inserted at left side of the queue. Rear=" << rear << " Front=" << front << endl;
            Q[front--] = element;
            count++;
        }
        else {
            cout << "Queue is full. Cannot insert." << endl;
        }
    }

    void insertRear(int element) {
        if (!isFull()) {
            if (rear == len - 1) {
                rear = -1;
            }
            cout << element << " Inserted at the right side of the queue. Rear=" << rear << " Front=" << front << endl;
            Q[++rear] = element;
            count++;
        }
        else {
            cout << "Queue is full. Cannot insert." << endl;
        }
    }

    void removeRear() {
        if (!isEmpty()) {
            cout << "Removed " << Q[rear] << endl;
            Q[rear--] = NULL;
            count--;
        }
        else {
            cout << "Queue is empty. Cannot remove." << endl;
        }
    }

    void removeFront() {
        if(front != rear){
            if (!isEmpty()) {
            if (front == len - 1) {
                front = 0;
            }
            
            cout << "Removed " << Q[front+1] << endl;
            Q[++front] = NULL;
            count--;
        }
        else {
            cout << "Queue is empty. Cannot remove." << endl;
        }
        } else{
            Q[front] = NULL;
        }
        
    }

    void display() {
        cout << "Index \t Value \t Pointer" << endl;
        for (int i = 0; i < len; i++) {
            cout << i << "\t";
            cout << ((Q[i] == NULL) ? "empty" : to_string(Q[i]));
            cout << "\t";
            cout << ((rear == i) ? "Rear" : "");
            cout << ((front+1 == i) ? "Front" : "");
            cout << endl;
        }
    }
};

int main() {
    cout << "Program started!" << endl;
    DEQueue* q = new DEQueue();
    int inputElement;
    bool isRepeat = true;
    int commandNum;

    while (isRepeat) {
        cout << "\nPlease enter a number representing an operation in the following list (-1 to quit): " << endl;
        cout << "1. InsertRear()\n2. InsertFront() \n3. RemoveRear() \n4. RemoveFront() \n5. Display() \n";
        cin >> commandNum;

        switch (commandNum) {
        case 1:
            cout << "\nEnter a value that you want to insert at the rear: ";
            cin >> inputElement;
            q->insertRear(inputElement);
            break;

        case 2:
            cout << "\nEnter a value that you want to insert at the front: ";
            cin >> inputElement;
            q->insertFront(inputElement);
            break;

        case 3:
            q->removeRear();
            break;

        case 4:
            q->removeFront();
            break;

        case 5:
            q->display();
            break;

        default:
            isRepeat = false;
            break;
        }
    }
    cout << "\nProgram has ended" << endl;
}
