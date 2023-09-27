#include<iostream>

using namespace std;

int main(){

    int arr[5]= {1,5,2,5,6};

    int count=0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5-i-1; j++){
            cout<<"running for the "<<count<< "th "<<endl;
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
            count++;
        }
    }
    cout<<"Sorted array is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<" "<<arr[i]<<"\n";
    }
}