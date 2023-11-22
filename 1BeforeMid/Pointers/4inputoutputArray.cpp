#include<iostream>
using namespace std;

int main(){
    int Array1[5];
    //taking an array of pointers;
    int* ArrayPointer[5];
    for(int i =0; i<5; i++){
        cout<<"Please enter "<<i;
        cin>>Array1[i];
        ArrayPointer[i]= &Array1[i];
    }

    for(int i=0; i<5; i++){
        cout<<i<<"th term is: "<<*ArrayPointer[i]<<endl;
    }


    return 0;
}