#include<iostream>

using namespace std;
class Temp{
    int a;
    int b;

    public:
    void ShowMembers(){
        cout<<"showing members a: "<<a<<" and b: "<<b<<endl;

    }
};

class Stack{

int Top = -1;
Temp* arrPtr[4];

public:

void push(Temp* ptr)
{
    if(Top!=3){

    arrPtr[++Top] = ptr;
    cout<<"Pushed the pointer onto index: "<<Top<<endl;
    }else{
        cout<<"Sorry the stack is full"<<endl;
    }

}

Temp* pop(){
    if(Top <= 3){
        return arrPtr[Top--];
    }else{
        cout<<"Sorry the stack is full"<<endl;
        return NULL;
    }
}




};


int main(){

    //create stack then Temp objects and push them onto the Stack object

    Stack stack;
    Temp* tempPtr = new Temp();
    tempPtr->ShowMembers();
    stack.push(tempPtr);
    tempPtr = new Temp();
    tempPtr->ShowMembers();
    stack.push(tempPtr);
    tempPtr = new Temp();
    tempPtr->ShowMembers();
    stack.push(tempPtr);
    tempPtr = new Temp();
    tempPtr->ShowMembers();

    stack.push(tempPtr);

    stack.push(tempPtr);
    stack.push(tempPtr);

    
    //pop the objects from the stack and call the ShowMembers() function on them
    stack.pop()->ShowMembers();

}