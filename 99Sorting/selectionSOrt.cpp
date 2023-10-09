#include<iostream>

using namespace std;

int main(){

    int arr[6] = {7,4,10,8,3,1};

    for(int i=0; i<5; i++){

        for(int j=1+i; j<6; j++){
            if(arr[j]< arr[i]){
                int temp = arr[j];
                arr[j]= arr[i];
                arr[i] = temp;

            }
        }
    }

    cout<<"\nThe sorted array is: "<<endl;
    for(int i=0; i<6; i++){
        cout<<arr[i]<< " , ";

    }
}