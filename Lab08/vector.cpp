#include <iostream>
#include <vector>

using namespace std;

void printMemVec(const vector<int>& vec) {
	printf("Vector - Each int is worth %lu bytes\n" , sizeof(vec[0]));
	for (size_t i = 0; i < vec.size(); i++) {
		printf("Value: %i at Memory Location: %p\n", vec[i], &vec[i]);
	}
}

void incVecBy10(vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) { 
		vec[i] += 10; 
	}
}

int main() {
	const int SIZE = 5;
	vector<int> vec(SIZE);
	for (int i = 0; i < SIZE; i++) {
		vec[i] = 100 + i;
	} 
	printf("Before -----------\n");
	printMemVec(vec);
	incVecBy10(vec);
	printf("After  -----------\n");
	printMemVec(vec);
	return 0;
} 
