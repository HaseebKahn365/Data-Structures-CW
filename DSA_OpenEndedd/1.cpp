#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to find the next prime number greater than or equal to n
int nextPrime(int n) {
    while (!isPrime(n)) {
        ++n;
    }
    return n;
}

// Function to encrypt a message using a key
string encrypt(const string& message, int key) {
    string encryptedMessage = "";

    for (char ch : message) {
        encryptedMessage += char(int(ch) + key);
    }

    return encryptedMessage;
}

// Function to decrypt a message using a key
string decrypt(const string& encryptedMessage, int key) {
    string decryptedMessage = "";

    for (char ch : encryptedMessage) {
        decryptedMessage += char(int(ch) - key);
    }

    return decryptedMessage;
}

int main() {
    // Choose a key (prime number)
    int key;
    cout << "Enter a prime number as the key: ";
    cin >> key;

    // Ensure the key is prime
    key = nextPrime(key);

    // Get the message from the user
    string message;
    cout << "Enter a message: ";
    cin.ignore();
    getline(cin, message);

    // Encrypt the message
    string encryptedMessage = encrypt(message, key);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    // Decrypt the message
    string decryptedMessage = decrypt(encryptedMessage, key);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
