#include<iostream>
using namespace std;

void SelectionSort(int* arr, int len){
    for(int i = 0; i < len - 1; i++){
        int jMin = i;
        for(int j = i + 1; j < len; j++){
            if (arr[j] < arr[jMin]) {
                // Update the index of the minimum element
                jMin = j;
            }
        }
        if (jMin != i) {
            // Swap the elements only once after the inner loop
            int temp = arr[i];
            arr[i] = arr[jMin];
            arr[jMin] = temp;
        }
    }
}

int main()
{
    freopen("outputTextFile.txt","w", stdout);  
    int arr[5] = {24,6,3,6,0};
    SelectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }


    cout<<"\nprogram complete";
}