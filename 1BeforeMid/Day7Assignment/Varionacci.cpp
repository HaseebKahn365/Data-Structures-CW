#include <iostream>
#include<chrono>

using namespace std;
using namespace chrono;

void fib(int);
void recFib(int);
int recursion(int);

int main()
{

    int limit;
    cout << "Enter the number of elements of varionacci: ";
    cin >> limit;



    auto startTime = high_resolution_clock::now();

    fib(limit); //calling the iterative function

    auto endTime = high_resolution_clock::now();

    auto differenceTime = duration_cast<microseconds>(endTime - startTime);

    cout<<"\nThe time taken (micrososecond) in iterative method was: "<<differenceTime.count();

    cout << "\nThe following is done through recursion" << endl;

    auto startTime2 = high_resolution_clock::now();

    recFib(limit); //calling the recursive function

    auto endTime2 = high_resolution_clock::now();

    auto differenceTime2 = duration_cast<seconds>(endTime2 - startTime2);

    cout<<"\nThe time taken (seconds) in recursive method was: "<<differenceTime2.count();

}

long long int a = 2, b = 2, c = 3, d;

void fib(int lim)
{
    for (int i = 0; i < lim-3; i++)
    {
        if (i == 0)
        {
            cout << a << ", " << b << ", " << c << ", ";
        }

        d = a + b;
        a = b;
        b = c;
        c = d;

        cout << d << ", ";
    }
}

long long int recursion(long long int n)
{

    if (n == 0)
    {
        return 2;
    }
    else if (n == 1){
        return 2;
    }
    else if (n == 2){
        return 3;
    }
    else{
        return recursion(n - 3) + recursion(n - 2);
    }
}

void recFib(int lim)
{

    for (long long int i = 0; i < lim; i++){
        cout << recursion(i) << ", ";
    }
}