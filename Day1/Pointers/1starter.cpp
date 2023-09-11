
#include<iostream>
using namespace std;

int main(){
    int var1 =23;
    int* varPointer = &var1;
    cout<<"var1 = "<<var1<<endl;
    //formate the adress output to int
    cout<<"var1 adress = "<<reinterpret_cast<uintptr_t>(varPointer)<<endl;
    cout<<"var1 = "<<*varPointer<<endl;
}