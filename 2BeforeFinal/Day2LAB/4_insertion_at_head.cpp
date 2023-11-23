#include<iostream>
#include<stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class item {
public:
    int age;
    item* next = NULL;
    item(int a) : age(a) {}
    void display() {
        cout << "Item with age: " << age << endl;
    }
};

class DoublyLinkedList {
    item* head = NULL;
    item* tail = NULL;
    int count = 0;
public:
    bool isEmpty() {
        return count == 0;
    }

    void insertFront(item* i) {
        i->next = head;
        head = i;
        if (tail == nullptr) {
            tail = i;
        }
        count++;
    }

    //method to delete the last item from the list without using the tail
    void deleteLast() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        item* prev = NULL;
        item* curr = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
        count--;
    }

};

void testInsertion(DoublyLinkedList* dll, int N) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        item* it = new item(rand() % 100);
        dll->insertFront(it);
    }

    auto stop = high_resolution_clock::now();
    cout << duration_cast<microseconds>(stop - start).count() << "" << endl;
}

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList();

    // Test for insertion at the head with N = 5, 20, 50, 100, 1000
    testInsertion(dll, 5);
    testInsertion(dll, 14);
    testInsertion(dll, 29);
   testInsertion(dll, 49);
    testInsertion(dll, 999);

    return 0;
}
