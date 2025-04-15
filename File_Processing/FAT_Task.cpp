#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)
struct FATEntry {
    uint16_t cluster;
};
#pragma pack(pop)

void readFATTable(const string &filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open FAT table file!" << endl;
        exit(1);
    }

    vector<FATEntry> fatTable;
    FATEntry entry;
    while (file.read(reinterpret_cast<char *>(&entry), sizeof(FATEntry))) {
        fatTable.push_back(entry);
    }
    file.close();

    cout << "FAT Table Analysis:\n";
    for (size_t i = 0; i < fatTable.size(); i++) {
        cout << "Cluster " << setw(5) << i << " -> " << hex << fatTable[i].cluster << dec << endl;
    }
}

int main() {
    string fatFilename = "fat_data.img"; // Updated FAT table file name
    readFATTable(fatFilename);
    return 0;
}
