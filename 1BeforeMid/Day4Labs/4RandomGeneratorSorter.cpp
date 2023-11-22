

// Call both functions created in task 1 and task 2 from the main function with the float array in 
// task 3 as parameter to both the functions. Display the sorted array returned by each function.

#include<iostream>
#include "sortLibraries/bubble.h"
#include "sortLibraries/insertion.h"
#include "sortLibraries/randomGenerator.h"
#include<chrono>
using namespace std;
using namespace chrono;
int main(){


float array [1000] ;

InitArray(array, 1000);


auto startTime = high_resolution_clock::now();

bubbleSort(array, 1000);

auto endTime = high_resolution_clock::now();

auto differenceTime = duration_cast<microseconds>(endTime - startTime);

cout<<"Duration in microseconds for Bubble Sort : "<<differenceTime.count();



InitArray(array, 1000);


 startTime = high_resolution_clock::now();

bubbleSort(array, 1000);

 endTime = high_resolution_clock::now();

 differenceTime = duration_cast<microseconds>(endTime - startTime);

cout<<"\n\nDuration in microseconds for Insertion sort: "<<differenceTime.count();

cout<<"\n\n";
for(int i=0; i<1000; i++){
    cout<<array[i]<< " ";
}








    return 0;
}