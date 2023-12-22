#include <iostream>
#include <unordered_map>
#include <bitset>
#include <queue>

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

    void buildHuffmanTree(const std::unordered_map<char, unsigned>& frequencyMap) {
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> minHeap;

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

    void buildHuffmanCodeTable(HuffmanNode* node, std::unordered_map<char, std::string>& codeTable, std::string code = "") {
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

    std::string encode(const std::string& text) {
        std::unordered_map<char, unsigned> frequencyMap;

        for (char ch : text) {
            frequencyMap[ch]++;
        }

        buildHuffmanTree(frequencyMap);

        std::unordered_map<char, std::string> codeTable;  
        buildHuffmanCodeTable(root, codeTable);

        std::string encodedText = "";
        for (char ch : text) {
            encodedText += codeTable[ch];
        }

        return encodedText;
    }

    std::string decode(const std::string& huffmanTree, const std::string& encodedText) {
        // Reconstruction of Huffman tree from the transmitted data (huffmanTree)
        // ... (Implement Huffman tree reconstruction logic here)

        // Decode the Huffman encoded text
        std::string decodedText = "";
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

class SimpleSubstitutionCipher {
private:
    std::unordered_map<char, char> encryptionKey;

public:
    SimpleSubstitutionCipher() {
        // ... (same as your existing constructor)
    }

    std::string encrypt(const std::string& message) {
        // ... (same as your existing encrypt function)
    }

    std::string decrypt(const std::string& encryptedMessage) {
        // ... (same as your existing decrypt function)
    }
};

class SecureTextTransmitter {
private:
    SimpleSubstitutionCipher substitutionCipher;
    HuffmanCoding huffmanCoding;

public:
    std::string broadcaster(const std::string& text) {
        if (text.length() < 10000) {
            // Use substitution cipher for small text
            return substitutionCipher.encrypt(text);
        } else {
            // Use Huffman coding for large text
            std::string compressedText = huffmanCoding.encode(text);
            // Transmit Huffman tree here
            return compressedText;
        }
    }

    std::string receiver(const std::string& transmittedData) {
        // Check the first bit to determine the encryption method
        bool isSubstitutionCipher = transmittedData[0] == '1';

        if (isSubstitutionCipher) {
            // Use substitution cipher decrypter
            return substitutionCipher.decrypt(transmittedData.substr(1));
        } else {
            // Use Huffman coding to decode the remaining stream
            // You may need to extract the Huffman tree from the transmitted data
            std::string huffmanTree; // Extract the Huffman tree
            std::string compressedText = transmittedData.substr(1);
            return huffmanCoding.decode(huffmanTree, compressedText);
        }
    }
};

int main() {
    SecureTextTransmitter transmitter;

    // Example: Broadcasting a message
    std::string originalText = "Hello, this is a test message.";
    std::string transmittedData = transmitter.broadcaster(originalText);

    // Example: Receiving the transmitted data
    std::string receivedText = transmitter.receiver(transmittedData);

    // Print results
    std::cout << "Original Text: " << originalText << std::endl;
    std::cout << "Transmitted Data: " << transmittedData << std::endl;
    std::cout << "Received Text: " << receivedText << std::endl;

    return 0;
}
