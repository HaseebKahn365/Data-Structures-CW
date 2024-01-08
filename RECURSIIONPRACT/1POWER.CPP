#include<iostream>
using namespace std;

int cal(int num, int power){
    if(power == 0) {
        return 1;
    }

    if(num == 0){
        return 0;
    }
    int first = cal(num, --power);
    int result = num * first ;
    return result;
}

int main()
{
    cout<<cal(3,7)<<endl;
    
    return 0;
}