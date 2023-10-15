#include<iostream>
#include<stdlib.h>
using namespace std;

int binarySearch(int* arr, int len, int searchTerm){

    int min = arr[0];
    int max = arr[len - 1];

    while(min<=max){ // we say less than or equal to make sure that we stop after looking at the matching values of the min and max
        int mid = (min + max) / 2;

        if(arr[mid] == searchTerm){
            return mid;
        }        
        else if( arr[mid] > searchTerm){
            max = mid ;

        }else{
            min = mid;
        }
    }
    return -1;

}

int main()
{
    freopen("outputTextFile.txt","w", stdout);
    int arr[5] = {1,2,3,5,6};
    
    cout<<"Calling the binarySearch to search for 5";
    int index = binarySearch(arr, 5, 6);

    cout<<"\nItem found at index = "<< index;
    


    return 0;
}