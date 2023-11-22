#include<iostream>
using namespace std;

int main(){
    cout<<"Please enter the number: ";
    int num;
    int* ptr = &num;
    cin>>*ptr;
    cout<<"You entered: "<<*(&num);

}