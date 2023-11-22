#include<iostream>
#include <cstdlib>  // Required for rand() function
#include <ctime> 
using namespace std;





void InitArray(float arr[], int N) {


    for (int i = 0; i < N; i++) {

        float randomFloat = (rand()%1000 ) *(0.9 - rand()%1);

        arr[i] = randomFloat;
    }
}



int main(){


cout<<"Enter the number of random floating points elements: ";

int size;
cin>> size;

float array[size];

InitArray(array, size);


for(int i=0; i<size; i++){
    cout<<array[i]<<endl;
}





}


