#include<iostream>
using namespace std;


class item{

    public:
    int data;
    item(int d): data(d){}

};

class HashTable{
    static const int size =11;
    item* hashArr[size];

    public:
    int quadraticHash(int data){
        int index = data%size;
        int probe = 0;
        while(hashArr[index]!=NULL){
            index +=  (probe*probe) % size;
            probe++;
        }
        cout<<"index = "<<index<<endl;
        return index;
    }

    void insert(item* i){
        int index = quadraticHash(i->data);
        hashArr[index] = i;
    }
};

int main(){

    HashTable* ht = new HashTable();
    ht->insert(new item(12));
    ht->insert(new item(23));
    ht->insert(new item(34));
}