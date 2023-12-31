#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

class item{


    public:
    int data;
    item* next= NULL;
    item* previous = NULL;
    item(int d): data(d){}

    void display(){
        cout<<"Displaying item with data: "<<data<<endl;
    }


};

class DEQLinkedList{
    item* head= NULL;
    item* tail= NULL;
    int count = 0;
    public:

    void insertFirst(item* i){
        if(head == NULL){// cout<<"First item inserted on front!"<<endl;
            head = i;
            tail = i;
            count++;
        }else{//cout<<"Item inserted on the front!"<<endl;
            i->next = head;
            head->previous = i;
            head = i;
            count++;
        }
    }
    void swapData(item* cur){ //this is for bubble sort:
        int tempData = cur->data;
        cur->data = cur->next->data;
        cur->next->data = tempData;
    }

     void swapDataInsertion(item* p1, item* p2){ //this is for bubble sort:
        int tempData = p1->data;
        p1->data = p2->data;
        p2->data = tempData;
    }

//!------------> Bubble sorting algorith <------------------!//
   void sortTheListBubbly() {


       auto start_time = high_resolution_clock::now();

    // Performing the insertion sort

      if (head == nullptr || head->next == nullptr) return;
    
    item* curr;
    item* lastUnsorted = nullptr;

    for (int i = 0; i < count - 1; i++) {
        curr = head;
        while (curr->next != lastUnsorted) {
            if (curr->data > curr->next->data) {
                swapData(curr);
            }
            curr = curr->next;
        }
        lastUnsorted = curr;
    }

    // Get the current time (end time)
    auto end_time = high_resolution_clock::now();

    // Calculate the time difference in microseconds
    auto duration = duration_cast<microseconds>(end_time - start_time);

    // Print the time difference
    cout<< duration.count() << std::endl;

   
}

//!------------> Insertion sorting algorith <------------------!//

    void insertionSort(item* curr){
        
        while(curr->previous != NULL){
            if(curr->previous->data > curr->data){
                swapData(curr->previous); 
            }
            curr= curr->previous;
        }
    }


    void sortTheListInsertly(){

         auto start_time = high_resolution_clock::now();

    // Performing the insertion sort


     if(head == NULL || head->next == NULL) return;

        item* curr = head->next;
        while(curr != NULL){
            insertionSort(curr);
            curr=curr->next;
        }


    // Get the current time (end time)
    auto end_time = high_resolution_clock::now();

    // Calculate the time difference in microseconds
    auto duration = duration_cast<microseconds>(end_time - start_time);

    // Print the time difference
    cout<< duration.count() << std::endl;
       
    }



    void insertLast(item* i){
        if(tail== NULL){//cout<<"First item inserted on the rear!"<<endl;
            head = i;
            tail = i;
            count++;
        }else{//cout<<"item is inserted at the last!"<<endl;
            tail->next = i;
            i->previous = tail;
            tail = i;
            count++;
        }
    }

    item* removeFirst(){
        if(count == 0){
            cout<<"You have not even inserted any items! Error: 100"<<endl;
            return NULL;
        }else{cout<<"Removed top!"<<endl;
            item* temp;
            temp= head;
            head = head->next;
            head->previous = NULL; //Making the front null after removal
            count--;
            return temp;
        }
    }

   item* removeLast() {
        if (tail == NULL) {
            cout << "You have not even inserted any items! Error: 101" << endl;
            return NULL;
        }
        else {
            cout << "\nRemoved last!" << endl;
            item* temp = tail;
            if (tail->previous != NULL) {
                tail->previous->next = NULL;
            }
            else {
                head = NULL; // If the list is empty after removal make the head null
            }
            tail = temp->previous;
            count--;
            return temp;
        }
    }
    void displayAll(){
        if(head!=NULL){
        item* curr= head; int i=1;
                    cout<<"item no. 1"<<endl;
        curr->display();

        while(curr->next != NULL){
            curr= curr->next;
            cout<<"item no. "<<i+1<<endl;
            curr->display();
            i++;
        } 
        }else{
            cout<<"\nCannot display data of an empty list\n";
        }
       
    }

    void printState(){
        cout<<"\n<-------Printing the state of the DEQ-----> \nHead: "<<head<<endl;
        cout<<"Tail: "<<tail<<endl;
        cout<<"Count: "<<count<<"\n\n";
    }
};

    // srand((time(0)));
int randGenerator(){
    return rand() % 10000 + 1;
}
void automatedTestForInsertion(DEQLinkedList* &d){

        cout<<"\nSorting the list insertly (duration: microseconds)\n";
        cout<<"For N=10, N=100, N=1000\n";

    for(int i=0; i<10; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListInsertly();

    for(int i=0; i<100; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListInsertly();

    for(int i=0; i<1000; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListInsertly();

    for(int i=0; i<10000; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListInsertly();

    
}


void automatedTestForBubble(DEQLinkedList* &d){

        cout<<"\n\n\nSorting the list bubbly (duration: microseconds)\n";
        cout<<"For N=10, N=100, N=1000\n";

    for(int i=0; i<10; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListBubbly();

    for(int i=0; i<100; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListBubbly();

    for(int i=0; i<1000; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListBubbly();

     for(int i=0; i<10000; i++){
        d->insertFirst( new item(randGenerator()) );
    }
    d->sortTheListBubbly();

    
}



int main()
{
    //srand((time(0)));
    freopen("out.txt", "w", stdout);
    cout<<"This is the Start of the program:"<<endl;

    // DEQLinkedList* DEQ2 = new DEQLinkedList();
    // automatedTestForBubble(DEQ2);
    // DEQ2->displayAll();
    
    DEQLinkedList* DEQ1 = new DEQLinkedList();
    automatedTestForInsertion(DEQ1);
    DEQ1->displayAll();
  



    
    cout<<"\n\n\nThe end";

    return 0;
}