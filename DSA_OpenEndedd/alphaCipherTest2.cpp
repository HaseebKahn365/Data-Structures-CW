#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

string input1 = "This is the basic test that will be test in case if the length of the texxt is less that the 10000 mark";

unordered_map<bool, string> encryptedTextData;




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


//Here is the logic for the Huffman's tree:


class HuffmanNode {
public:
    char data;
    unsigned frequency;
    HuffmanNode* left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

class HuffmanCoding {
private:
    HuffmanNode* root;

    void deleteTree(HuffmanNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void buildHuffmanTree(const unordered_map<char, unsigned>& frequencyMap) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

        for (const auto& pair : frequencyMap) {
            minHeap.push(new HuffmanNode(pair.first, pair.second));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();
            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;

            minHeap.push(internalNode);
        }

        root = minHeap.top();
    }

    void buildHuffmanCodeTable(HuffmanNode* node, unordered_map<char, string>& codeTable, string code = "") {
        if (node) {
            if (node->data != '\0') {
                codeTable[node->data] = code;
            }
            buildHuffmanCodeTable(node->left, codeTable, code + "0");
            buildHuffmanCodeTable(node->right, codeTable, code + "1");
        }
    }

public:
    HuffmanCoding() : root(nullptr) {}

    ~HuffmanCoding() {
        deleteTree(root);
    }

    string encode(const string& text) {
        unordered_map<char, unsigned> frequencyMap;

        for (char ch : text) {
            frequencyMap[ch]++;
        }

        buildHuffmanTree(frequencyMap);

        unordered_map<char, string> codeTable;  
        buildHuffmanCodeTable(root, codeTable);

        string encodedText = "";
        for (char ch : text) {
            encodedText += codeTable[ch];
        }

        return encodedText;
    }
    
    //function to display the encoded bit stream

    void displayEncodedText(){
        for(int i = 0; i < encryptedTextData[true].size(); i++){
            cout<<encryptedTextData[true][i];
        }
        cout<<endl;
        
    }

    string decode(const string& huffmanTree, const string& encodedText) {

        // Decode the Huffman encoded text
        string decodedText = "";
        HuffmanNode* current = root;
        for (char bit : encodedText) {
            if (bit == '0') {
                current = current->left;
            } else {
                current = current->right;
            }

            if (current->left == nullptr && current->right == nullptr) {
                decodedText += current->data;
                current = root;
            }
        }

        return decodedText;
    }
};

//! the transciever:

class Transciever
{
public:
    // encrypting the text:
    AlphaSubstitutionCipher *alphaSubsitue = new AlphaSubstitutionCipher();
    void mainEncrypter()
    {

        if (input1.length() < 10000)
        {
            input1 = alphaSubsitue->encrypt(input1);
            cout<<"The encrypted data is: " << input1 << endl;
            encryptedTextData[true] = input1;
        }
        else
        {
            // use the Huffman's tree to compress the text and append with false at beginning
            HuffmanCoding huffmanCoding;
            string encodedText = huffmanCoding.encode(input1);
            huffmanCoding.displayEncodedText();
            encryptedTextData[false] = encodedText;
        }
    }

    void mainDecrypter()
    {
        // check if the encryptedTextData has a true key then use the decrypt method of the alphasubstitute 
        if (encryptedTextData.find(true) != encryptedTextData.end())
        {
            input1 = alphaSubsitue->decrypt(encryptedTextData[true]);
        }
        
        else
        {
            // use the Huffman's tree to decompress text
        }
    }
};

int main()
{
    Transciever *transciever = new Transciever();
    transciever->mainEncrypter();
    transciever->mainDecrypter();
    cout << input1 << endl;
    return 0;
}
