#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

class BufferSimulator {
private:
    vector<char> buffer;
    size_t bufferSize;

public:
    BufferSimulator(size_t size) : bufferSize(size) {
        buffer.reserve(bufferSize);
    }

    void writeData(ifstream &input, ofstream &output) {
        char ch;
        while (input.get(ch)) {
            buffer.push_back(ch);
            if (buffer.size() >= bufferSize) {
                flushBuffer(output);
            }
        }
        flushBuffer(output);
    }

    void flushBuffer(ofstream &output) {
        for (char c : buffer) {
            output.put(c);
        }
        buffer.clear();
    }
};

int main() {
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";
    size_t bufferSize = 1024; // Buffer size in bytes

    ifstream inputFile(inputFilename, ios::binary);
    ofstream outputFile(outputFilename, ios::binary);
    
    if (!inputFile || !outputFile) {
        cerr << "Error: Cannot open files!" << endl;
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();
    BufferSimulator buffer(bufferSize);
    buffer.writeData(inputFile, outputFile);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Data transfer completed in " << elapsed.count() << " seconds." << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}