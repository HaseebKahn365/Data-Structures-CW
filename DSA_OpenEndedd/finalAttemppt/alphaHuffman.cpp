

#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//! AlphaSubstitution 

string message;
string encryptedMessageAlS;
//vector to store the bool for huffman
vector<bool> huffmanBool;


bool shortFlag;

void checkFlag(){
    if
}

class AlphaSubstitutionCipher
{
private:
    unordered_map<char, char> encryptionKey;

public:
    AlphaSubstitutionCipher()
    {

        encryptionKey = {
            {'a', 'x'}, {'b', 'm'}, {'c', 'q'}, {'d', 'p'}, {'e', 'z'}, {'f', 'l'}, {'g', 'a'}, {'h', 'b'}, {'i', 'n'}, {'j', 'o'}, {'k', 'c'}, {'l', 'd'}, {'m', 'e'}, {'n', 'f'}, {'o', 'g'}, {'p', 'h'}, {'q', 'i'}, {'r', 'j'}, {'s', 'k'}, {'t', 'r'}, {'u', 's'}, {'v', 't'}, {'w', 'u'}, {'x', 'v'}, {'y', 'y'}, {'z', 'w'}};
    }

    string encrypt(const string &message)
    {
        string encryptedMessage = "";
        for (char ch : message)
        {

            if (isalpha(ch))
            {
                char encryptedChar = encryptionKey[tolower(ch)];

                encryptedMessage += isupper(ch) ? toupper(encryptedChar) : encryptedChar;
            }
            else
            {
                encryptedMessage += ch;
            }
        }
        return encryptedMessage;
    }

    string decrypt(const string &encryptedMessage)
    {

        unordered_map<char, char> decryptionKey;
        for (const auto &entry : encryptionKey)
        {
            decryptionKey[entry.second] = entry.first;
        }

        string decryptedMessage = "";
        for (char ch : encryptedMessage)
        {

            if (isalpha(ch))
            {
                char decryptedChar = decryptionKey[tolower(ch)];

                decryptedMessage += isupper(ch) ? toupper(decryptedChar) : decryptedChar;
            }
            else
            {
                decryptedMessage += ch;
            }
        }
        return decryptedMessage;
    }
};



int main()
{
    
    return 0;
}