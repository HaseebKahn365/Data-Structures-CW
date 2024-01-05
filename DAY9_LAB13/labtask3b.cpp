#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 2069;

class HashTable {
private:
    string* table[TABLE_SIZE];

    int hashFunction(const string &key) {
        int sum = 0;
        for (int i = 0; i < key.length(); ++i)
            sum += (key[i] * (i + 1));

        return sum % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insertQuadraticProbing(const string &key) {
        int index = hashFunction(key);
        int i = 1;

        while (table[index] != nullptr) {
            index = (index + i * i) % TABLE_SIZE;
            i++;
        }

        table[index] = new string(key);
    }

    void search(const string &key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int probe = 1;

        while (table[index] != nullptr) {
            if (*table[index] == key) {
                cout << "Found " << key << " at index " << index << endl;
                return;
            }

            index = (originalIndex + probe * probe) % TABLE_SIZE; 
            probe++;
        }

        cout << key << " not found in the hash table." << endl;
    }

    
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            delete table[i];
        }
    }
};

int main() {
    HashTable* quadraticProbingTable = new HashTable();

    
    quadraticProbingTable->insertQuadraticProbing("abcdef");
    quadraticProbingTable->insertQuadraticProbing("bcdefa");
    quadraticProbingTable->insertQuadraticProbing("xyz");

    quadraticProbingTable->search("abcdef");
    quadraticProbingTable->search("bcdefa");
    quadraticProbingTable->search("xyz");

    
    delete quadraticProbingTable;

    return 0;
}
