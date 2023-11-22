#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Please enter a 5 digit number: "; //123
    cin>>num;
    for(int i = 0; i<5; i++){
        int show = num%10;
        num/=10;
        cout<<"\n"<<show;
    }

    return 0;
}