#include<iostream>
#include<string>
using namespace std;

class HashTable{
    const static int tbsize = 2069;
    string* hashArr[tbsize];
    
    public:
    HashTable(){
        for (int i = 0; i < 2069; i++)
        {
            hashArr[i] = NULL;
        }
        
    }
    //hashfunction:
    int hashFunction(string str){
        int sum = 0;
        for(int i=0; i<str.length(); i++){
            sum+= (str[i])*(i+1);
        }
        return sum%tbsize;
        

    }
    //insertion linear:
    void insert(string str) {
    int index = hashFunction(str);

    while (hashArr[index] != NULL) {
        index++;
    }

    // Creating a new string pointer to store the string
    string* newString = new string(str);

    // Inserting the string pointer at the calculated index in the hashArr
    hashArr[index] = newString;
}

    //displaying
    void displaying(){

          for (int i = 0; i < 2069; i++)
        {
            if(hashArr[i] != NULL){
                cout<<"index "<<i<<" : "<<*hashArr[i]<<endl;
            }
        }
    }
};

int main()
{
    HashTable* ht = new HashTable();
    ht->insert("abcdef");
    ht->insert("bcdefa");
    ht->insert("haseeb");
    ht->insert("bilal");
    ht->displaying();
    
    return 0;
}