#include<iostream>
using namespace std;

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int arr[10] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 1};

    quickSort(arr, 0, 9);

   
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (true) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex + 1, high);
    }
}
