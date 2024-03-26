#include <iostream>
#include <fstream>
using namespace std;

void writeToFile(string filename, string *arr, int sample_size) {
    ofstream file(filename);
    for (int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    cout << "Wrote to " << filename << endl;
}

void writeToFile(string filename, char *arr, int sample_size) {
    ofstream file(filename);
    for (int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    cout << "Wrote to " << filename << endl;
}

void writeToFile(string filename, int *arr, int sample_size) {
    ofstream file(filename);
    for (int i = 0; i < sample_size; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    cout << "Wrote to " << filename << endl;
}

void readFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
       cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    const int SAMPLE_SIZE = 2;
    string array_str[SAMPLE_SIZE] = {"cat", "dog"};
    
    string str_file = "array_str.csv";
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    cout << "Reading file:" << endl;
    readFile(str_file);

    return 0;
}
