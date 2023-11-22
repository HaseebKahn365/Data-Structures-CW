#include <iostream>

using namespace std;

int main()
{

    int arr[7] = {1, 5, 8, 16, 18, 19, 22};

    cout << "Enter the search item: ";

    int search;

    cin >> search;

    // int min = arr[0];
    // int max = arr[6];
    // int

    cout << "Performing a linear search..." << endl;

    for (int i = 0; i < 7; i++)
    {

        if (arr[i] == search)
        {
            cout << "Item found at : " << i << endl;
            return i;
        }
    }
    cout << "item not found";
}