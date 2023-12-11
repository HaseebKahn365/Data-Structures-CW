#include<iostream>
using namespace std;

class Airplane{
    public:
    int arr_time;
    Airplane* left;
    Airplane* right;
    int nAirplanes;

    Airplane(int arr_time){
        this-> arr_time = arr_time;
         left = NULL;
         right = NULL;
         int nAirplanes =1; //number of airplanes in the subtree;
    }

};

class AirplaneTree{
    Airplane* root;
    Airplane* rankArray[100]; //containing all the planes upto the rank

    //TODO: INSERTING THE PLANE WITH THE KEY
    
};

int main()
{
    
    return 0;
}