#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

string message;
string encryptedMessageAlS;
vector<bool> huffmanBool;

bool shortFlag;

bool checkFlag()
{
    if (message.length() < 1000)
    {
        shortFlag = true;
        return true;
    }
    shortFlag = false;
    return false;
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

class HuffmanNode
{
public:
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

class Compare
{
public:
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

class HuffmanTree
{
private:
    unordered_map<char, string> huffmanCodes;

    void encode(HuffmanNode *root, string str)
    {
        if (!root)
            return;

        if (root->data != '$')
            huffmanCodes[root->data] = str;

        encode(root->left, str + "0");
        encode(root->right, str + "1");
    }

public:
    HuffmanNode *buildHuffmanTree(const string &text)
    {
        priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;

        unordered_map<char, unsigned> frequencyMap;
        for (char ch : text)
        {
            frequencyMap[ch]++;
        }

        for (auto &entry : frequencyMap)
        {
            HuffmanNode *node = new HuffmanNode(entry.first, entry.second);
            minHeap.push(node);
        }

        while (minHeap.size() != 1)
        {
            HuffmanNode *left = minHeap.top();
            minHeap.pop();

            HuffmanNode *right = minHeap.top();
            minHeap.pop();

            HuffmanNode *internalNode = new HuffmanNode('$', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;

            minHeap.push(internalNode);
        }

        HuffmanNode *root = minHeap.top();
        encode(root, "");
        return root;
    }

    void compress(const string &text)
    {
        for (char ch : text)
        {
            string code = huffmanCodes[ch];
            for (char bit : code)
            {
                huffmanBool.push_back(bit == '1');
            }
        }
    }

    string decompress()
    {
        string decompressedMessage = "";
        HuffmanNode *current = buildHuffmanTree(message);
        for (bool bit : huffmanBool)
        {
            if (bit)
                current = current->right;
            else
                current = current->left;

            if (current->left == nullptr && current->right == nullptr)
            {
                decompressedMessage += current->data;
                current = buildHuffmanTree(message);
            }
        }
        return decompressedMessage;
    }
};

HuffmanTree* huffmanTree =  new HuffmanTree();

class Transceiver
{
private:
    AlphaSubstitutionCipher alphaSubstitutionCipher;

public:
    void encrypt()
    {
        if (checkFlag()){

            encryptedMessageAlS = alphaSubstitutionCipher.encrypt(message);
            cout << "The encrypted message is: " << encryptedMessageAlS << endl;
        }


        else
        {
            int count = 0;
            //before encryption the number of bits are
            for(char ch: message){
                count+=8;
            }
            cout<<"Before encryption the number of bits are: "<<count<<endl;

            HuffmanNode *root = huffmanTree->buildHuffmanTree(message);
            huffmanTree->compress(message);
            //display the entire array
            for (bool bit : huffmanBool)
            {
                cout << bit;
            }
            //after encryption the number of bits are:
            cout<<"\n\nAfter encryption the number of bits are: "<<huffmanBool.size()<<endl;
            cout << endl;
        }
    }

    void decrypt()
    {
        if (checkFlag())
            message = alphaSubstitutionCipher.decrypt(encryptedMessageAlS);

        else
        {
            message = huffmanTree->decompress();
            for (bool bit : huffmanBool)
            {
                cout << bit;
            }
            cout << endl<<"\n\n";
            cout<<"The decrypted message is: "<<message<<endl;


        }
    }
};


int main()
{
    message = "The quick brown fox jumps over the lazyGenerally speaking, the process of decompression is simply a matter of translating the stream of prefix codes to individual byte values, usually by traversing the Huffman tree node by node as each bit is read from the input stream (reaching a leaf node necessarily terminates the search for that particular byte value). Before this can take place, however, the Huffman tree must be somehow reconstructed. In the simplest case, where character frequencies are fairly predictable, the tree can be preconstructed (and even statistically adjusted on each compression cycle) and thus reused every time, at the expense of at least some measure of compression efficiency.Generally speaking, the process of decompression is simply a matter of translating the stream of prefix codes to individual byte values, usually by traversing the Huffman tree node by node as each bit is read from the input stream (reaching a leaf node necessarily terminates the search for that particular byte value). Before this can take place, however, the Huffman tree must be somehow reconstructed. In the simplest case, where character frequencies are fairly predictable, the tree can be preconstructed (and even statistically adjusted on each compression cycle) and thus reused every time, at the expense of at least some measure of compression efficiency. dogGenerally speaking, the process of decompression is simply a matter of translating the stream of prefix codes to individual byte values, usually by traversing the Huffman tree node by node as each bit is read from the input stream (reaching a leaf node necessarily terminates the search for that particular byte value). Before this can take place, however, the Huffman tree must be somehow reconstructed. In the simplest case, where character frequencies are fairly predictable, the tree can be preconstructed (and even statistically adjusted on each compression cycle) and thus reused every time, at the expense of at least some measure of compression efficiency.";

    Transceiver* transceiver = new Transceiver();
    transceiver->encrypt();
    transceiver->decrypt();

    cout << "\n\n the end" << endl;

   

    return 0;
}
