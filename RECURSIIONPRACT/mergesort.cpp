#include<iostream>
using namespace std;

void conquer(int arr[], int si, int mid, int ei){
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x++] = arr[idx1++];
        } else {
            merged[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid) {
        merged[x++] = arr[idx1++];
    }

    while (idx2 <= ei) {
        merged[x++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < (ei - si + 1); i++, j++) {
        arr[j] = merged[i];
    }
}

void divide(int arr[], int si, int ei){
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    int arr[7] = {3, 4, 2,5,6,1,9};
    divide(arr, 0, 6);  
    cout << "\n\n";

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
