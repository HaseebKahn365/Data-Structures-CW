#include "sortLibraries/bubble.h"
#include "sortLibraries/insertion.h"
#include<iostream>

using namespace std;

int main(){

    cout<<"Please enter the size of the array: " ;
    int size;
    cin>> size;

    float array [size];
    cout<<"\n Now enter the float elements of the array: "<<endl;

    for(int i=0; i<size; i++){
         cin>>array[i];
        
    }

    bubbleSort(array, size);

    cout<<"Sorted using bubble sort: \n";

    for(int i=0; i<size; i++){
        cout<<array[i]<<endl;
    }

    cout<<"\naddress of array"<<array<<"\n\n";


   cout<<"\n\nPlease enter the size of the array: " ;
     size;
    cin>> size;

     array [size];
    cout<<"\n Now enter the float elements of the array: "<<endl;


    for(int i=0; i<size; i++){
         cin>>array[i];
        
    }

    
    cout<<"Sorted using insertion sort: \n";
  
  insertionSort(array, size);

  for(int i=0; i<size; i++){
    cout<<array[i]<<endl;
  }

cout<<"\naddress of array"<<array<<"\n";
    

}