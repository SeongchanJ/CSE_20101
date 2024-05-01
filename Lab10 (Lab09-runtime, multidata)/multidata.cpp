#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm> // for sort

using namespace std;

template <typename T>
void vecGen(string filename, vector<T> &v) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: Unable to open file " << filename << endl;
    return;
  }
  T num;
  v.clear();
  while (file >> num) {
    v.push_back(static_cast<T>(num));
  }
  file.close();
}

template <typename T>
int iterativeSearch(const vector<T> &v, T elem) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == elem) {
      return i;
    }
  }
  return -1;
}

template <typename T>
int binarySearch(const vector<T> &v, int start, int end, T elem) {
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

int main() {
  // Populate v with 10000 sorted numbers (integers)
  vector<int> v;
  vecGen("10000_numbers.csv", v);

  // Test elements to search for (integers)
  vector<int> elem_to_find;
  vecGen("test_elem.csv", elem_to_find);

  // Search tests for integers
  cout << "Iterative Search Results (Integers):" << endl;
  for (int i = 0; i < elem_to_find.size(); i++) {
    int elem = elem_to_find[i];
    clock_t start = clock();
    int index_if_found = iterativeSearch(v, elem);
    clock_t end = clock();
    double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);
    cout << index_if_found << ": " << elapsed_time_in_sec << " seconds" << endl;
  }

  cout << "\nBinary Search Results (Integers):" << endl;
  for (int i = 0; i < elem_to_find.size(); i++) {
    int elem = elem_to_find[i];
    clock_t start = clock();
    int index_if_found = binarySearch(v, 0, v.size() - 1, elem);
    clock_t end = clock();
    double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);
    cout << index_if_found << ": " << elapsed_time_in_sec << " seconds" << endl;
  }

  // Populate d with 1000 doubles
  vector<double> d;
  vecGen("1000_double.csv", d);

  // Test elements to search for (doubles)
  vector<double> double_to_find;
  vecGen("double_to_find.csv", double_to_find);

  return 0;
}




