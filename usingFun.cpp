

#include<iostream>

using namespace std;

void bubbleSort(int array[], int len){

    int temp;

    for(int i=0; i<len; i++){

        for(int j=0; j<5-i-1; j++){

            if(array[j] < array[j+1]){

                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }

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

bubbleSort(array, size);
    
        cout<<"The sorted array is: "<<endl;

    for(int i=0; i<5; i++){

        cout<<"\n"<<array[i];
        
    }
}


