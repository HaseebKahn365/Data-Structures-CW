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

    int hashFunction2(const string &key) {
        int sum = 0;
        for (int i = 0; i < key.length(); ++i)
            sum += (key[i] * (i + 1));

        return 11 - sum % 11;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insertDoubleHashing(const string &key) {
        int index = hashFunction(key);
        int hash2 = hashFunction2(key);

        while (table[index] != nullptr) {
            index = (index + hash2) % TABLE_SIZE;
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

            index = (originalIndex + probe * probe) % TABLE_SIZE; // Use quadratic probing for search
            probe++;
        }

        cout << key << " not found in the hash table." << endl;
    }

};

int main() {
    HashTable* doubleHashingTable = new HashTable();

    
    doubleHashingTable->insertDoubleHashing("abcdef");
    doubleHashingTable->insertDoubleHashing("bcdefa");
    doubleHashingTable->insertDoubleHashing("xyz");

    doubleHashingTable->search("abcdef");
    doubleHashingTable->search("bcdefa");
    doubleHashingTable->search("xyz");

    
    delete doubleHashingTable;

    return 0;
}
