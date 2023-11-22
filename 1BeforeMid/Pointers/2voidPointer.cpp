#include<iostream>

using namespace std;

int main(){
    int num = 36;
    void* pointer;
    pointer = &num;
    cout<<"The adress of int varible is: "<<pointer<<endl;
    string name = "Abdul Haseeb";
    pointer = &name;
    cout<<"The adress of string varible is: "<<pointer<<endl;

    return 0;
}