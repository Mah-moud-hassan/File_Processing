#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt and decrypt using XOR
void encryptDecrypt(string &text, char key) {
    for (char &c : text) {
        c ^= key;
    }
}

// Function to read text from a file
string readFromFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file!" << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// Function to write text to a file
void writeToFile(const string &filename, const string &content) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file for writing!" << endl;
        exit(1);
    }
    file << content;
    file.close();
}

int main() {
    string filename = "input.txt";
    string encryptedFilename = "encrypted.txt";
    string decryptedFilename = "decrypted.txt";
    char key = 'K'; // Encryption key

    // Read text from file
    string text = readFromFile(filename);
    cout << "Original text:\n" << text << endl;

    // Encrypt text
    encryptDecrypt(text, key);
    writeToFile(encryptedFilename, text);
    cout << "Text encrypted and saved in " << encryptedFilename << endl;

    // Decrypt text
    string decryptedText = readFromFile(encryptedFilename);
    encryptDecrypt(decryptedText, key);
    writeToFile(decryptedFilename, decryptedText);
    cout << "Text decrypted and saved in " << decryptedFilename << endl;

    return 0;
}
