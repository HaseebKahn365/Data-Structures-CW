#include<iostream>
using namespace std;

class item{
    int age;
    float gpa;
    public:
    item* next = NULL;
    item(int a, float g) : age(a), gpa(g) {}
    void display(){
        cout<<"\nItem with age: "<<age <<"gpa: "<<gpa<<endl;
    }
};

class LinkedList{
    int count=0;
    item* head = NULL;
    item* tail = NULL;

    public:
    void insertRear(){
        
    }
};


int main()
{
    
    return 0;
}