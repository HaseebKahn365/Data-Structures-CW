

#include<iostream>

using namespace std;

void bubbleSort(int array[], int len){

    int temp;

    for(int i=0; i<len; i++){

        for(int j=0; j<5-i-1; j++){

            if(array[j] < array[j+1]){

                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }

    }

}



int main(){

    cout<<"Please enter the size of the array: " ;
    int size;
    cin>> size;

    int array [size];
    cout<<"\n Now enter the elements of the array: "<<endl;

    for(int i=0; i<size; i++){
         cin>>array[i];
        
    }

bubbleSort(array, size);
    
        cout<<"The sorted array is: "<<endl;

    for(int i=0; i<5; i++){

        cout<<"\n"<<array[i];
        
    }
}


#include<iostream>
using namespace std;

class item{
    float gpa;
    public:
    int Age;
    item* next = NULL;

    void display(){
        cout<<"\nDisplaying: Age: "<<Age<<" gpa: "<< gpa;
    }

    item(int m, float g){
        Age = m;
        gpa = g;
    }
};

class linkedList{
    item* head = NULL;
    int count = 0;

    public:

    void putInList(item* i){
        item* curr = head; item* prev = NULL;
        while(curr ->next != NULL){
            if(curr->Age >=i->Age){

                cout<< i->Age<<" vs breaking  "<<curr->Age<<endl;
                break;
            }
                cout<<curr->Age<<" vs "<< i->Age<<endl;
            curr = curr -> next;
            prev = curr;
            
        }
        if(prev == NULL){
             cout<<"Inserted in the front"<<endl;
            // i->next = head;
            // head = i;
             if(curr->Age >=i->Age){
                //insert after
                curr -> next = i;
                i-> next = curr;
             }
        }else{
            if(prev->next = NULL){
                 cout<<"Inserted at the last;"<<endl;
                prev->next = i;
            }else{
                cout<<"Inserted in the middle;"<<endl;
                i->next = prev -> next;
                prev->next = i;
            }
        }
    }
    
    void insertSorted(item* i){

        if(head == NULL){
            cout<<"Inserted on the head"<<endl;

            head = i;

        }else{

           putInList(i);

        }
    }
    

    item* removeSorted(){

        if(head == NULL){

            return NULL;

        }else{
            
            item* current = head;

            head = head -> next;

            return current;

        }

    }

    void displayAll(){ //not callable on empty list
      item* temp = head;
      while(temp -> next != NULL){
        temp->display();
        temp = temp-> next;
      }
    }
};

int main()
{
     freopen("out.txt", "w", stdout);
    linkedList* myList = new linkedList();

            myList->insertSorted(new item(1, 3.5));
    myList->insertSorted(new item(2, 3.5));
     myList->insertSorted(new item(2, 3.5));
      myList->insertSorted(new item(4, 3.5));
            myList->insertSorted(new item(5, 3.5));
        myList->insertSorted(new item(19, 3.5));


      myList->insertSorted(new item(70, 3.5));
      myList->insertSorted(new item(10, 3.5));
      myList->insertSorted(new item(70, 3.5));
      

      myList->displayAll();


     
    
    return 0;
}