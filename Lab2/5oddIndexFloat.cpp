#include<iostream>

using namespace std;

int main(){
    cout<<"Please enter the 10 float values\n\n";

    float Array[10];

    for(int i=0; i<10; i++){

        cout<<"Please enter the float at ["<<i<<"] : ";
        cin>>Array[i];

    }

    cout<<"\nNow using pointer arithematic to print the values of the float array:\n\n";

    for(int i=1; i<10; i+=2){
        cout<<"\nThe float value at the index["<<i<<"] is: "<<*(Array+i);
    }
}