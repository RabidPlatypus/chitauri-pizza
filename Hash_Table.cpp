#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
	int table_size;
	list<int>* table;
public:
	HashTable(int key);
	int HashFunction(int key) { return key % table_size; };
	bool LinearInsert(int key);
	bool QuadraticInsert(int key);
	void DeleteElement(int key);
	void HashDisplay();
};

HashTable::HashTable(int size) {
	this->table_size = size;
	table = new list<int>[table_size];
}

bool HashTable::LinearInsert(int key) {
	int index = HashFunction(key);
	int probed = 0;
	int N = table_size;
	while (probed < N) {
		if (table[index].empty()) {
			table[index].push_back(key);
			return true;
		}
		index = HashFunction(index + 1);
		++probed;
	}
	return false;
}

bool HashTable::QuadraticInsert(int key) {
	int i = 0;
	int probed = 0;

	int index = HashFunction(key);
	while (probed < table_size) {
		if (table[index].empty()) {
			table[index].push_back(key);
			return true;
		}
		i += 1;
		index = HashFunction((HashFunction(key) + i*i));
		probed += 1;
	}
	return false;
}

void HashTable::DeleteElement(int key) {
	for (int i = 0; i < table_size; i++) {
		for (auto j : table[i])
			if (j == key) {
				table[i].clear();
				break;
			}
	}
}

void HashTable::HashDisplay() {
	for (int i = 0; i < table_size; i++) {
		cout << i;
		for (auto j : table[i])
			cout << " ==> " << j;
		cout << endl;
	}
	cout << endl;
}

int main() {
	int arr[] = {44,4,16,28,21 };
	int n = sizeof(arr) / sizeof(arr[0]);

	HashTable ht(11);
	for (int i = 0; i < n; i++)
		ht.LinearInsert(arr[i]);
	cout << "Original Table" << endl;
	ht.HashDisplay();
	cout << "Linear Insert" << endl;
	ht.LinearInsert(26);
	ht.HashDisplay();
	cout << "Remove Element 26" << endl;
	ht.DeleteElement(26);
	ht.HashDisplay();
	cout << "Quadratic Insert" << endl;
	ht.QuadraticInsert(26);
	ht.HashDisplay();
	


	return 0;
}