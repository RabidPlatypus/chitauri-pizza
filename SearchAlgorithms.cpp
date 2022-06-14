#include <iostream>
#include <string>

using namespace std;

template <typename T>
void LinearSearch(T input[], int size, T key) {
	int n = 1;
	int i;
	for (i = 0; i < size; i++) {
		if (input[i] == key) {
			cout << "The value of " << key << " was found! Its index is " << i << endl;
			cout << "Linear Search Algorithm compared " << n << " elements before finding the key." << endl;
			break;
		}
		else {
			n += 1;;
		}
	}
	if (input[i] != key) {
		n -= 1;
		cout << "The value of " << key << " was not found." << endl;
		cout << "Linear Search Algorithm compared " << n << " elements before making this decision." << endl;
	}
}

template <typename T>
void BinarySearch(T input[], int size, T key) {
	T temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (input[i] > input[j]) {
				temp = input[j];
				input[j] = input[i];
				input[i] = temp;
			}
		}
	}
	int n = 0;
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right){
		mid = (right + left) / 2;
		if (input[mid] == key) {
			cout << "The value of " << key << " was found! Its index is " << mid << endl;
			cout << "Binary Search Algorithm compared " << n << " elements before finding the key." << endl;
			break;
		}
		else if (input[mid] > key) {
			n += 1;
			right = mid - 1;			
		}
		else if (input[mid] < key) {
			n += 1;
			left = mid + 1;			
		}
	}
	if(input[mid] != key){
		cout << "The value of " << key << " was not found." << endl;
		cout << "Binary Search Algorithm compared " << n << " elements before making this decision." << endl;
	}
}

template <typename T>
void DoubleSearch(T input[], int size, T key) {
	LinearSearch(input, size, key);
	cout << endl;
	BinarySearch(input, size, key);
	cout << endl;
}

int main() {
	int Array1[6] = { -2, -4, 0, 3, 1, 5 };
	string Array2[5] = { "hello", "John", "C++", "GPA", "Graduation" };
	double Array3[5] = { -2.0, -4.5, 0.5, 3.4, 1.2 };

	DoubleSearch(Array1, 6, 3);
	DoubleSearch(Array1, 6, -10);
	DoubleSearch(Array2, 5, string("Smith"));
	DoubleSearch(Array2, 5, string("GPA"));
	DoubleSearch(Array3, 5, -2.0);
	DoubleSearch(Array3, 5, 5.1);




	return 0;
}
