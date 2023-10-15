#include<iostream>
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

class linkedList{
    item* head = NULL;
    int count =0;

    public:
    
    void insertFirst(item* i){
        cout<<"Inserting no."<<count+1<<" Item: \n";

        if(head == NULL){

            head = i;
            count++;

        }else{

           i -> Next = head;
           head = i;
           count++;

        }
    }
    

    item* remove(){

        if(head == NULL){
            count--;

            return NULL;

        }else{
            
            item* current = head;

            head = head -> Next;
            count--;

            return current;

        }

    }
    int showSize(){
        return count;
    }

    void displayAll(){
        item* temp = head;
        while(temp != NULL){
            temp -> display();
            temp= temp -> Next;
        }
    }

    void RemoveN(int n) {
    item* current = head;
    item* prev = nullptr;

    while (current != NULL) {
        if (current->age == n) {
            cout << "Item found and removed:" << endl;
            current->display();

            if (prev == NULL) {
                // If the item to remove is the first item, update the head pointer.
                head = current->Next;
            } else {
                // Update the previous item's Next pointer to skip the removed item.
                prev->Next = current->Next;
            }

            // Deallocate memory for the removed item.
            delete current;

            count--;
            return; // Exit the function after removing the first matching item.
        }

        prev = current;
        current = current->Next;
    }

    cout << "Could not find the item!" << endl;
}


};

int main()
{
    freopen("out.txt","w", stdout);
     linkedList* myList = new linkedList();
   myList->insertFirst(new item(23, 3.5));
     myList->insertFirst(new item(24, 3.5));
      myList->insertFirst(new item(25, 3.5));
      myList->insertFirst(new item(27, 3.5));
      myList->insertFirst(new item(25, 3.8));

    myList -> RemoveN(25);
    cout<<"\nProgram ended";

    
    
 
    return 0;
}