#include<iostream>

using namespace std;

int avgCalculator(int* , int);
int main(){

int array[5] = {2,2,3,4,6};

int avg = avgCalculator(array, 5);

cout<<"The average of the odd integers is: "<< avg;


}

int avgCalculator(int* arr, int size){

    int sum=0;

    for(int i=1; i<size; i+=2){
        sum+= *(arr+i);
    }

    return sum/(size/2);
}