#include<iostream>
using namespace std;
const int capacity = 5;

void insertionSort(int* arr, int len){
    // declaring the essential variables:
    int i, j, temp;
    for(i=1; i<len; i++){
        
        temp = arr[i];

       for(j=i; j>0 && temp<arr[j-1]; j--){
        //replace the 2nd smaller [j] item with greater first item [j-1]:
        arr[j] = arr[j-1];
       }
        //replace the moved duplicate first with smaller temp
        arr[j] = temp;
        
    }

}

int main()
{
    freopen("outputTextFile.txt", "w", stdout);
    int arr[5] = {4,3,7,9,5};
    insertionSort(arr, 5);
        cout<<"The sorted elements using the insertion with for loop sort are: "<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i]<<"     ";
    }
    return 0;
}

