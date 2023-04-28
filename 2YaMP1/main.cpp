#include "HashTable.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n = 1;
	int size;
	datatype elem;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> size;
	HashTable hashTable(size);
	while (n != 0) {
		cout << "Выберете действие: " << endl;
		cout << "1-добавить элемент/элементы, 2-удалить элемент, 3-напечатать хеш-таблицу" << endl;
		cout << "0-выход" << endl;
		cin >> n;
		switch (n) {
		case 1:
			cout << "Введите количество элементов: " << endl;
			int count;
			cin >> count;
			cout << "Введите элементы: " << endl;
			for (int i = 0; i < count; i++) {
				cin >> elem;
				hashTable.add(elem);
			}
			break;
		case 2:
			cout << "Введите элемент, который хотите удалить: " << endl;
			cin >> elem;
			hashTable.remove(elem);
			break;
		case 3:
			hashTable.printHashTable();
		}
	}
	return 0;
}