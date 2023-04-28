#include "HashTable.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n = 1;
	int size;
	datatype elem;
	cout << "������� ������ ���-�������" << endl;
	cin >> size;
	HashTable hashTable(size);
	while (n != 0) {
		cout << "�������� ��������: " << endl;
		cout << "1-�������� �������/��������, 2-������� �������, 3-���������� ���-�������" << endl;
		cout << "0-�����" << endl;
		cin >> n;
		switch (n) {
		case 1:
			cout << "������� ���������� ���������: " << endl;
			int count;
			cin >> count;
			cout << "������� ��������: " << endl;
			for (int i = 0; i < count; i++) {
				cin >> elem;
				hashTable.add(elem);
			}
			break;
		case 2:
			cout << "������� �������, ������� ������ �������: " << endl;
			cin >> elem;
			hashTable.remove(elem);
			break;
		case 3:
			hashTable.printHashTable();
		}
	}
	return 0;
}