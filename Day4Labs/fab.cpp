

#include<iostream>

using namespace std;

int fib(int n);

int global[5] ={-1,-1,-1,-1,-1};

int main(){
    int lim, ans;
    cout<<"Please enter the limit of the fab: "<<endl;
    cin>>lim;
    ans = fib(lim); 
    cout<<"The answer is: "<<ans;

    
//code for fibonacci series

// int n = 10; // number of terms to generate
// int a = 0, b = 1, c;
// cout << a << " " << b << " "; // print the first two terms

// for (int i = 2; i < n; i++) {
//     c = a + b;
//     cout << c << " ";
//     a = b;
//     b = c;
// }

int n = 5;
int result = fib(n);

cout<<"The result is: "<<result<<endl;




    // return 0;


}

// int fib(int n){

//     if(n<=1){
//         return n;
//     }

    

//     global[0] = 0;
//     global[1] = 1;

//     for(int i=2; i<=n; i++){
//         global[i] = global[i-2] + global[i-1];
//     }

//     return global[n];
// }




//now using recursion

int fib(int n){
    if(n==0){ 
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-2) + fib(n-1);
    }
}

//using the optimal approach