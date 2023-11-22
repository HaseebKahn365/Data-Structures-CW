#include<iostream>
using namespace std;

const int capacity = 3;

class item{
    int age;
    float gpa;

    public:

    item(int a, int g){
        age = a;
        gpa = g;
    }

    void displayItem(){
        cout<<"Displaying item: Age = "<<age <<" GPA = "<< gpa<<endl;
    }
    
};

class Stack{
    item* arr[capacity];

    int top = -1;

    public:

    void push(item* i){
        if(top < capacity -1){
            arr[++top] = i;
        }else{
            cout<<"\nStack Overflow!\n";
        }
    }

    item* pop(){
        if(top == -1){
            cout<<"\nNo Items to pop!\n";
            return NULL;
        }else{
            return arr[top --];
        }
    }

};

int main()
{
    freopen("outputTextFile.txt","w", stdout);
    Stack* s = new Stack();

    s-> push( new item(34, 2.1) );
    s-> push ( new item(35, 3.14) );
    s-> push ( new item(36, 3.7) );
    s-> push ( new item(35, 3.25) );

    s -> pop() -> displayItem();
    s -> pop() -> displayItem();
    s -> pop() -> displayItem();
    if( s -> pop() != NULL){
            s -> pop() -> displayItem();
    }



    return 0;
}