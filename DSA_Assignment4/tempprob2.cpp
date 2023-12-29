#include <iostream>
#include <string>
using namespace std;

class HashTable {
    int count;
    int size;
    string* hashArr;

public:
    HashTable() {
        size = 11;
        count = 0;
        hashArr = new string[size];
        for (int i = 0; i < size; i++) {
            hashArr[i] = "-1";
        }
    }

    ~HashTable() {
        delete[] hashArr;
    }

    int hashFunction(string str) {
        int hashVal = 0;
        for (int i = 0; i < str.length(); i++) {
            int letter = str[i] - 96; // get char code
            hashVal = (hashVal * 27 + letter) % size;
        }
        return hashVal;
    }

    // insertion
    void insertString() {
        if (count == size - 1) {
            cout << "No more room for strings" << endl;
            return;
        }
        string inputStr = "";
        while (inputStr.length() == 0) {
            cout << "Enter string: ";
            cin >> inputStr;
        }

        int index;
        index = hashFunction(inputStr);
        while (hashArr[index] != "-1") {
            index++; // linear probing
        }
        hashArr[index] = inputStr;
        count++;
        float loadfactor = static_cast<float> (count) /size;
        if (loadfactor > 0.5) {
            cout<<"We are giving call to the rehash load factor: "<<loadfactor<<endl;
            // moving the hashtable:
            rehash();
        }
    }

void rehash() {
    int newSize = getNextPrime();
    string* temp = new string[newSize];

    for (int i = 0; i < size; i++) {
        if (hashArr[i] != "-1") {
            int index = hashFunction(hashArr[i]);
            while (temp[index] != "-1") {
                index = (index + 1) % newSize;
            }
            temp[index] = hashArr[i];
        }
    }

    delete[] hashArr;
    hashArr = temp;
    size = newSize;
    cout << "Rehash complete" << endl;
}



    int getNextPrime() {
        int newSize = 2 * size;
        while (!isPrime(newSize)) {
            newSize++;
        }
        return newSize;
    }

   bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


    void displayTable() {
        cout << "Index :\t"
             << "String:\n";
        for (int i = 0; i < size; i++) {
            cout << i << "\t" << hashArr[i] << endl;
        }
    }
};

int main() {
    HashTable* ht = new HashTable();

    int op;
    while (true) {
        cout << "What do you want?" << endl;
        cout << "1) insert string." << endl;
        cout << "2) display string." << endl;
        cout << "Any other key to quit." << endl;
        cin >> op;
        switch (op) {
        case 1:
            ht->insertString();
            break;

        case 2:
            ht->displayTable();
            break;

        default:
            cout << "Program ended";
            exit(0);
            break;
        }
    }
}
