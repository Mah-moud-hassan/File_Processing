#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

// Function to replace a word in a given text
void replaceWord(string &text, const string &oldWord, const string &newWord) {
    size_t pos = 0;
    while ((pos = text.find(oldWord, pos)) != string::npos) {
        text.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }
}

int main() {
    string filename = "input.txt";
    string outputFilename = "output.txt";
    string oldWord, newWord;

    // Get words from user
    cout << "Enter the word to be replaced: ";
    cin >> oldWord;
    cout << "Enter the new word: ";
    cin >> newWord;

    // Read text from file
    string text = readFromFile(filename);
    cout << "Original text:\n" << text << endl;

    // Replace word
    replaceWord(text, oldWord, newWord);
    writeToFile(outputFilename, text);
    cout << "Updated text saved in " << outputFilename << endl;

    return 0;
}
