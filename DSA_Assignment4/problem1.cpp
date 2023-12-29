
#include<iostream>
#include<string>
using namespace std;


 class HashTable{
    int count;
    string hashArr[11];

    public:

    HashTable(){
        count=0;
        for(int i=0; i<11; i++){
            hashArr[i] = "-1";
        }
    }


    int hashFunction(string str){
        int hashVal=0;
        for(int i=0; i<str.length(); i++){
            int letter = str[i] - 96; //get char code
            hashVal = (hashVal * 27 + letter) % 11;
        }
        return hashVal;
    }
    
    //insertion
    void insertString(){
        if(count==9) {
            cout<<"No more room for strings"<<endl; return;
        }
        string inputStr = "";
        while (inputStr.length()==0)    
        {
        cout<<"Enter string: ";
        cin>>inputStr;
        }
        
        int index;
        index = hashFunction(inputStr);
        while(hashArr[index]!="-1"){
            index++; //linear probing
            }
        hashArr[index] = inputStr;
        count++;
    }

    void displayTable(){
        cout<<"Index :\t"<<"String:\n";
        for(int i=0; i<11; i++){
            cout<<i<<"\t"<< hashArr[i]<<endl;
        }
    }


 };

 int main(){
    HashTable* ht = new HashTable();
        int op;
    while(true){
        cout<<"What do you want?"<<endl;
        cout<<"1) insert string."<<endl;
        cout<<"2) display string."<<endl;
        cout<<"Any other key to quit."<<endl;
        cin>>op;
        switch (op)
        {
        case 1:
            ht->insertString();
            break;

        case 2:
            ht->displayTable();
            break;
        
        default:
        cout<<"Program ended";
        exit(0);
            break;
        }

    }
 }