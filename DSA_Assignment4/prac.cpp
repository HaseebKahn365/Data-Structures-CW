#include<iostream>
using namespace std;

class item {
public:
    int data;

    item(int d) {
        data = d;
    }
};

class HashTable {
    static const int size = 11; // Use 'const' for in-class initialization of static member
    int count = 0;

    item* hashArr[size];

public:
    bool isFull() {
        return count == size;
    }

    int hashFunction(int data) {
        return (data % size);
    }

    void insert(item* i) {
        int index = hashFunction(i->data);
        if (isFull()) {
            cout << "no more room" << endl;
            return;
        }
        int probe = 0;
        while (hashArr[index] != NULL) {
            probe++;
            cout<<"probe: "<<probe<<endl;
            index++;
            if (index == size) // Wrap around if the end of array is reached
                index = 0;
        }
        cout << "index = " << index << endl;
        hashArr[index] = i;
        count++;
    }
};

int main() {
    HashTable* ht = new HashTable();
    ht->insert(new item(24));
    ht->insert(new item(35));
    ht->insert(new item(46));


    return 0;
}
