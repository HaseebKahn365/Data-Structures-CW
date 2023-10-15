#include<iostream>
using namespace std;
const int capacity = 5;

void insertionSort(int* arr, int len){
    // declaring the essential variables:
    int i, j, temp;
    for(i=1; i<len; i++){
        j=i;
        temp = arr[i];

        while(j>0 && temp < arr[j-1]){
            //assign the smaller value ie temp to arr[j-1]
            arr[j] = arr[j-1];
            j--;
        }
        //make the first 
        arr[j] = temp;
        
    }

}

int main()
{
    freopen("outputTextFile.txt", "w", stdout);
    int arr[5] = {1,4,1,6,0};
    insertionSort(arr, 5);
        cout<<"The sorted elements using the insertion sort is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<"     ";
    }
    return 0;
}

