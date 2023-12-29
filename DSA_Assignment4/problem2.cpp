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
        float loadfactor = count / static_cast<float>(size);
        if (loadfactor > 0.5) {
            // moving the hashtable:
            size = getNextPrime();
        }
    }

    int getNextPrime() {
        int newSize = 2 * size;
        while (true) {
            if (isPrime(newSize)) {
                return newSize;
            }
            newSize++;
        }
    }

    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    void testPrime() {
        for (int i = 0; i < 20; i++) {
            if (isPrime(i)) {
                cout << i << endl;
            }
        }
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
    ht->testPrime();
    return 0;

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
