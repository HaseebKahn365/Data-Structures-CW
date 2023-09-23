

#include<iostream>

using namespace std;

int main(){
    int size;
    cout<<"Please enter the size of the array: ";
    cin>>size;

   int Array[size];

   for(int i=0; i<size; i++ ){
    cout<<"Please enter the item at index "<<i<<": ";
    cin>>Array[i];
    

   }

   cout<<"\nNow printing the elements of the array\n";

   for(int i=0; i<size; i++){
    cout<<"The element at the Array["<<i<<"] is: "<<Array[i]<<endl;
   }


}