#include<iostream>
using namespace std;

    
void bubbleSort(int* arr, int len){

    for(int i = 0; i < len-1; i++){

        for(int j=0; j< len - i -1; j++){

            if(arr[j] > arr[j+1]){
                //doing the swap;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int main()
{
    freopen("outputTextFile.txt","w", stdout);

    int arr[8] = {1,5,2,4,0,-35,66,42};
    bubbleSort(arr, 8);
    cout<<"The  sorted items using bubble sort are: \n";
    for(int i=0; i<8; i++){
        cout<<arr[i]<<", ";
    }
    
    return 0;
}