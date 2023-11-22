
#include<iostream>
using namespace std;



int binarySearch(int arr[], int search, int size){

    int min = 0;
    int max = size -1;

    while(min<=max){

        int mid = (min+max)/2;

        if(arr[mid] == search){
            return mid;
        }
        else if(arr[mid] < search){
             min= mid+1;
        }
        else{
           max = mid -1;
        }
    }

    return -1;

}


int main(){

    int arr[7]={1,3,5,6,7,8,89};
    cout<<"Item is found at index: "<<binarySearch(arr, 8, 7);

}