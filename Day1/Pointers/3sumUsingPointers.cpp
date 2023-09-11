#include<iostream>
using namespace std;

int main(){
    int a = 23;
    int b =12;
    int* pointera =&a;
    int* pointerb = &b;
    int result = *pointera + *pointerb;
    cout<<"The result using pointers is: "<<result;
}