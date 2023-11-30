#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    char data;
    Node* right = NULL;
    Node* left = NULL;
    Node(int k, char c): key(k), data(c){}
    void display()
    {
        cout<<"Node with key= "<<key<<" and data= "<<data<<endl;
    }

};


class MyStack{

int Top = -1;
Node* arrPtr[150];

public:

bool isEmpty(){
  return  (Top == -1);; 
}

void pushNode(Node* ptr)
{
    if(Top!=149){

    arrPtr[++Top] = ptr;
    }else{
        cout<<"Sorry the stack is full"<<endl;
    }

}

Node* getTop(){
    if(Top == -1){
        return NULL;
    }
    return arrPtr[Top];
}

Node* popNode(){
    if(Top >= 0){
        return arrPtr[Top--];
    }else{
        return NULL;
    }
}




};