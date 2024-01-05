#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 2069;

class HashTable {
private:
    string table[TABLE_SIZE];

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

        return 2063 - sum % 2063;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = "";
    }

    void insertLinearProbing(const string &key) {
        int index = hashFunction(key);
        while (!table[index].empty())
            index = (index + 1) % TABLE_SIZE;

        table[index] = key;
    }

    void search(const string &key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int probe = 1;

        while (!table[index].empty()) {
            if (table[index] == key) {
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
    HashTable* linear = new HashTable();

    linear->insertLinearProbing("abcdef");
    linear->insertLinearProbing("bcdefa");
    linear->insertLinearProbing("xyz");

    linear->search("abcdef");
    linear->search("bcdefa");
    linear->search("xyz");

    return 0;
}
