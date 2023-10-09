
//for 5 elements int A = {8,5,7,3,2};

//No. of passes = 4

//No. of Comparisons = 1+2+3+4 OR Summation of odd int = n(n-1)/2 = O(n^2);

//No. of Swaps = 1+2+3+4 OR Summation of odd int = n(n-1)/2 = O(n^2);n


//Implementation of the bubble sort:
#include<iostream>
using namespace std;

void BubbleSort(int Arr[], int n){

    //we should be running four passes for 5 elements so,,,

    int count = 0;

    for(int i=0; i<n-1; i++){

        //Running less than n-j comparisons...

        //if the list is already sorted then the loop should break;

        bool isSorted = true;

        int temp;
        for(int j = 0; j<n-1-i; j++){

            if(Arr [j] >  Arr [j+1]){

                //Swapping the elements
                //look for the bigger element and move it to the right.

                temp = Arr [j];
                Arr [j] = Arr [j+1];
                Arr [j+1] = temp;
                isSorted = false;
                count++;

            }

            
        }
            if(isSorted == true){
                cout<<"\nArray is already sorted!\n\n";
                break;
            }
    }

    cout<<"Number of iterations : "<<count<<endl;
}


int main(){

    int Array [5] ={8,5,7,3,2};

    BubbleSort(Array, 5);

    cout<<"The sorted modified array is:"<<endl;

    for(int i = 0; i<5; i++) {
        cout<<Array[i]<<endl;
    }

      cout<<"Sorting array again:"<<endl;

      BubbleSort(Array, 5);

    for(int i = 0; i<5; i++) {
        cout<<Array[i]<<endl;
    }



}

//Stability Check.