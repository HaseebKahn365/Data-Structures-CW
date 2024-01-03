#include<iostream>
#include<string>
#include<chrono>
using namespace std;
using namespace chrono;

class HashTable {
    int count;
    string hashArr[11];

public:
    HashTable() {
        count = 0;
        for (int i = 0; i < 11; i++) {
            hashArr[i] = "-1";
        }
    }

    int hashFunction(string str) {
        int hashVal = 0;
        for (int i = 0; i < str.length(); i++) {
            int letter = str[i] - 96; // get char code
            hashVal = (hashVal * 27 + letter) % 11;
        }
        return hashVal;
    }

    void displayTable() {
        cout << "Index :\t" << "String:\n";
        for (int i = 0; i < 11; i++) {
            cout << i << "\t" << hashArr[i] << endl;
        }
    }

    void insertion(string str) {
        int index;
        index = hashFunction(str);
        while (hashArr[index] != "-1") {
            index = (index + 1) % 11;
        }
        hashArr[index] = str;
        count++;
    }

    void input5TestString() {
        for (int i = 0; i < 5; i++) {
            string inputStr = "Haseeb " + to_string(i);
            this->insertion(inputStr);
        }
    }

    void input7TestString() {
        this->insertion("Haseeb 5");
        this->insertion("Haseeb 6");
    }

    void input9TestString() {
        this->insertion("Haseeb 7");
        this->insertion("Haseeb 8");
    }

    void insertTestString() {
        // Load factor = 0.5 test
        input5TestString();
        displayTable();
        runSearchTests("Load Factor = 0.5");

        // Load factor = 0.7 test
        input7TestString();
        displayTable();
        runSearchTests("Load Factor = 0.7");

        // Load factor = 0.9 test
        input9TestString();
        displayTable();
        runSearchTests("Load Factor = 0.9");
    }

    void runSearchTests(const string& message) {
        int totalTimeinMicroseconds = 0;
        for (int i = 0; i < 10; i++) {
            int randomIndex = rand() % 10;
            string inputStr = "Haseeb " + to_string(randomIndex);

            auto start = high_resolution_clock::now();
            searchTestString(inputStr);
            auto end = high_resolution_clock::now();

            totalTimeinMicroseconds += duration_cast<microseconds>(end - start).count();
        }

        cout << "Average time taken to search 10 random strings " << message << ": "
            << totalTimeinMicroseconds / 10 << " microseconds" << endl;
    }

    void searchTestString(string str) {
        int index;
        index = hashFunction(str);
        int originalIndex = index;

        do {
            if (hashArr[index] == str) {
                cout << "Found string: " << str << endl;
                return;
            }
            index = (index + 1) % 11;
        } while (index != originalIndex && hashArr[index] != "-1");

        cout << "String not found: " << str << endl;
    }
};

int main() {
    HashTable* ht = new HashTable();
    ht->insertTestString();
    delete ht; // Don't forget to free the allocated memory
    return 0;
}
