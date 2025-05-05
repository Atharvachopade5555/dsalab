#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Record {
    int id;
    char name[20];  // Fixed-size character array for file-safe serialization
    int age;
};

void insertRecord(fstream &file, int pos, Record record) {
    file.seekp(pos * sizeof(Record), ios::beg);  // Move to the specified position
    file.write(reinterpret_cast<char*>(&record), sizeof(Record));  // Write the record
    cout << "Record inserted successfully at position " << pos << endl;
}

void deleteRecord(fstream &file, int pos) {
    Record blankRecord = {0, "", 0};  // Blank record
    file.seekp(pos * sizeof(Record), ios::beg);  // Move to position
    file.write(reinterpret_cast<char*>(&blankRecord), sizeof(Record));  // Overwrite
    cout << "Record deleted successfully from position " << pos << endl;
}

void displayFileContents(fstream &file) {
    file.seekg(0, ios::beg);  // Move to start
    Record record;
    int position = 0;
    
    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (record.id != 0) {
            cout << "Position " << position << ": ID = " << record.id 
                 << ", Name = " << record.name << ", Age = " << record.age << endl;
        }
        position++;
    }
}

int main() {
    fstream file("records.dat", ios::in | ios::out | ios::binary | ios::trunc);

    if (!file) {
        cout << "File could not be created!" << endl;
        return 1;
    }

    // Creating records
    Record r1 = {1, "Atharva", 25};
    Record r2 = {2, "Sohan", 30};
    Record r3 = {3, "Anuj", 22};
    
    insertRecord(file, 0, r1);
    insertRecord(file, 1, r2);
    insertRecord(file, 2, r3);

    cout << "\nFile contents after insertion:" << endl;
    displayFileContents(file);

    // Delete a record
    deleteRecord(file, 1);  // Delete Saisha

    cout << "\nFile contents after deletion:" << endl;
    file.clear();  // Clear EOF flag before reading again
    displayFileContents(file);

    file.close();
    return 0;
}

