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

  int hashFunction(string str) {
    int hashVal = 0;
    for (int i = 0; i < str.length(); i++) {
      int letter = str[i] - 96; // get char code
      hashVal = (hashVal * 27 + letter) % size;
    }
    return hashVal;
  }

  // Insertion
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

    int index = hashFunction(inputStr);
    while (hashArr[index] != "-1") {
      index++; // Linear probing
    }

    hashArr[index] = inputStr;
    count++;
    float loadfactor = static_cast<float>(count) / size;
    if (loadfactor > 0.5) {
      cout << "We are giving call to the rehash load factor: " << loadfactor << endl;
      // Moving the hashtable:
      rehash();
    }
  }
  
  //deleting string from the hash table

  void deleteString(string str) {
    int index = hashFunction(str);
    for(int i=0; i<size; i++){ //linear probing
        if(hashArr[index] == str){
            hashArr[index] = "-1";
            cout << "String killed wihtout mercy" << endl;
            return;
        }
        index++;
    }
    cout << "String not found on grounds" << endl;
  }

  // Display strings
   void displayTable() {
        cout << "Index :\t"
             << "String:\n";
        for (int i = 0; i < size; i++) {
            cout << i << "\t" << hashArr[i] << endl;
        }
    }

    int getNextPrime(int n) {
        int nextPrime = n;
        while (true) {
            nextPrime++;
            bool isPrime = true;
            for (int i = 2; i < (nextPrime/2)+1 ; i++) {
                if (nextPrime % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return nextPrime;
            }
        }
    }

  // Rehashing
    void rehash() {
    int newSize = getNextPrime(size * 2);  // Double the size for simplicity
    string* newHashArr = new string[newSize];

    for (int i = 0; i < newSize; i++) {
      newHashArr[i] = "-1";
    }

    // Rehash existing elements
    for (int i = 0; i < size; i++) {
      if (hashArr[i] != "-1") {
        int newIndex = hashFunction(hashArr[i]) % newSize;

        while (newHashArr[newIndex] != "-1") {
          newIndex++;  // Linear probing for the new array
        }

        newHashArr[newIndex] = hashArr[i];
      }
    }

    delete[] hashArr;  // Release memory for the old array
    hashArr = newHashArr;
    size = newSize;

    cout << "Rehash completed. New size: " << size << endl;
  }
};

int main() {
  HashTable* ht = new HashTable();

  while (true) {
    cout << "What do you want?" << endl;
    cout << "1) insert string." << endl;
    cout << "2) display string." << endl;
    cout << "3) delete string." << endl;
    cout << "Any other key to quit." << endl;

    int choice;
    cin >> choice;
        string str;

    switch (choice) {
      case 1:
        ht->insertString();
        break;
      case 2:
        cout << "Displaying strings:" << endl;
        ht->displayTable();
        break;
        case 3:
        cout << "Enter string to delete: ";
        cin >> str;
        ht->deleteString(str);
        break;
      default:
        return 0;
    }
  }

  return 0;
}
