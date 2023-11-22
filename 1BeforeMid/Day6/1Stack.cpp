#include<iostream>

using namespace std;

class Student{
    string name;
    int marks;

    public:
    Student(string Name, int Marks){
        name = Name;
        marks= Marks;
    }
    void display(){
        cout<<"Name: "<<name <<" The marks of students are: "<<marks<<endl;
    }


};


class Stack{
    Student* arr[10];
    int top;

    public:
    Stack(){
        top=-1;        
    }

    void push(Student* newStudent){

        if(top<9){
            arr[++top] = newStudent;
        }else{
            cout<<"The stack is full"<<endl;
        }

    }

    Student* pop(){
        if(top>-1){
            return arr[top--];
        }
    }

    void displayAll(){
        cout<<"Value of the top is"<<top;
        for (int i=top; i>=0; i--){
            arr[i]->display();
        }
    }


};

int main(){

    Stack* stackOfStudents = new Stack();

    for(int i=0; i<10; i++){

        stackOfStudents->push(new Student("Haseeb", i));

    }

    //displayin all the students in descending order

    stackOfStudents->displayAll();





}