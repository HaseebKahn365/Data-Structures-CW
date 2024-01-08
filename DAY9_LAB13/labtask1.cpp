#include<iostream>
#include<string>
using namespace std;

class HashTable{
    const static int tbsize = 2069;
    string* hashArr[tbsize];
    
    public:
    //hashfunction:
    int hashFunction(string str){
        int sum = 0;
        for(int i=0; i<str.length(); i++){
            sum+= (str[i])*(i+1);
        }
        return sum%tbsize;

    }
    //insertion:
    void insert(string str){
        int index = hashFunction(str);

        cout<<"The hashing function returned "<< index<<" for "<<str<<endl;
    }
};

int main()
{
    HashTable* ht = new HashTable();
    ht->insert("abcdef");
    ht->insert("bcdefa");
    
    return 0;
}