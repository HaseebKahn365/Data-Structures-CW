#include<iostream>

using namespace std;




void insertionSort(int arr[], int len){

     int i,j,temp;

    for(int i=1; i<len; i++){

        j=i;
        temp = arr[i];
        
        while(j>0 && temp> arr[j-1]){

            arr[j] = arr[j -1];

            j--;

        }

        arr[j] = temp;
        
    }

}



int main(){


    cout<<"Please enter the size of the array: " ;
    int size;
    cin>> size;

    int array [size];
    cout<<"\n Now enter the elements of the array: "<<endl;

    for(int i=0; i<size; i++){
         cin>>array[i];
        
    }


    insertionSort(array, size);

   

    cout<<"after sorting the array: "<<endl;

    for(int i=0; i<size; i++){
         cout<<array[i];
        
    }
}
