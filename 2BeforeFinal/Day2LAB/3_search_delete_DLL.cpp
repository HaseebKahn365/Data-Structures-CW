#include<iostream>
#include<stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
class item{
    
    public:
    int age;
    item* next = NULL;
    item(int a) : age(a) {}
    void display(){
        cout<<"Item with age: "<<age <<endl;
    }
};

class DoublyLinkedList{
    item* head = NULL;
    item* tail = NULL;
    int count = 0;
    public:
    bool isEmpty(){
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

    //method to delete the last iitem from the list without using the tail

    void deleteLast(){
        if(isEmpty()){
            cout<<"List is empty\n";
            return;
        }
        item* prev = NULL;
        item* curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }


};

void testDeletionLast(DoublyLinkedList* dll){
    int N = 5;
    for(int i=0; i<N; i++){
        item* it = new item(rand()%100);
        dll->insertFront(it);
    }
    //start the timer
    auto start = high_resolution_clock::now();
    dll->deleteLast();
    //stop the timer
    auto stop = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(stop - start).count()<< endl;

    //Similarly calculating the time for N = 20, 50, 100, 1000

    N = 16;
    for(int i=0; i<N; i++){
        item* it = new item(rand()%100);
        dll->insertFront(it);
    }

    start = high_resolution_clock::now();
    dll->deleteLast();
    stop = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(stop - start).count()<< endl;

    N = 31;
    for(int i=0; i<N; i++){
        item* it = new item(rand()%100);
        dll->insertFront(it);
    }

    start = high_resolution_clock::now();
    dll->deleteLast();
    stop = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(stop - start).count()  << endl;

    //insert enough items to make the list of size 100

    N = 71;
    for(int i=0; i<N; i++){
        item* it = new item(rand()%100);
        dll->insertFront(it);
    }

    start = high_resolution_clock::now();
    dll->deleteLast();
    stop = high_resolution_clock::now();
    cout<<duration_cast<microseconds>(stop - start).count()<< endl;

    //insert enough items to make the list of size 1000

    N = 929;
    for(int i=0; i<N; i++){
        item* it = new item(rand()%100);
        dll->insertFront(it);
    }

    start = high_resolution_clock::now();
    dll->deleteLast();
    stop = high_resolution_clock::now();

    cout<<duration_cast<microseconds>(stop - start).count()<< endl;



}


int main(){

    DoublyLinkedList* dll = new DoublyLinkedList();
    //test for deletion of last item in list of N=5 N=20 N=50 N=100 N=1000
    testDeletionLast(dll);

    return 0;
}