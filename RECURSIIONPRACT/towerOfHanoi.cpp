#include<iostream>
using namespace std;

void tower(int n, string s, string h, string d){

    if(n==1) {
        cout<<"Transfering "<<n<<" from "<<s<< " to "<< d<<endl;
        return;
    }

    tower(n-1, s, d, h);
    cout<<"Transfering "<<n<<" from "<<s<< " to "<< d<<endl;
    tower(n-1, h, s, d);
}

int main()
{
    tower(7, "S", "H","D");
    
    return 0;
}