#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

int iterativeSearch(vector<int> v, int elem) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> &v, int start, int end, int elem) {
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (v[mid] == elem) {
        return mid;
    } else if (v[mid] > elem) {
        return binarySearch(v, start, mid - 1, elem);
    } else {
        return binarySearch(v, mid + 1, end, elem);
    }
}

void vecGen(string filename, vector<int> &v) {
    ifstream file(filename);
    int num;
    v.clear();
    if (file.is_open()) {
        while (file >> num) {
            v.push_back(num);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void writeTimes(string filename, const vector<double> &times, const vector<int> &n) {
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec)" << endl;
    for (int i = 0; i < times.size(); i++) {
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(const vector<double> &a) {
    double sum = 0.0;
    for (double num : a) {
        sum += num;
    }
    return sum / a.size();
}

int main() {
    // populate v with 10000 sorted numbers
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // Sort the vector for binary search (binary search only works on sorted data)
    sort(v.begin(), v.end()); // using algorithm library

    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // Search tests
    cout << "Iterative Search Results:" << endl;
    for (int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_if_found = iterativeSearch(v, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);
        cout << index_if_found << ": " << elapsed_time_in_sec << " seconds" << endl;
    }

    cout << "\nBinary Search Results:" << endl;
    for (int i = 0; i < elem_to_find.size(); i++) {
        int elem = elem_to_find[i];
        clock_t start = clock();
        int index_if_found = binarySearch(v, 0, v.size() - 1, elem);
        clock_t end = clock();
        double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);
        cout << index_if_found << ": " << elapsed_time_in_sec << " seconds" << endl;
    }

    return 0;
}







