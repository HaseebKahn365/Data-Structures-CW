#include<iostream>

using namespace std;

int main(){

    cout<<"Pease enter the 8 integer: \n";
    int Array[8];

    for(int i=0; i<8 ; i++){
        cout<<"Please enter the no."<<i<<" item: ";
        cin>>Array[i];
    }

    cout<<"\nNow displaying the values of the array:\n\n";

    for(int i=7; i>=0; i--){
        cout<<"The number at index["<<i<<"] is: "<<Array[i]<<endl;
    }
}