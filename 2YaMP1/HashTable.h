#pragma once
#include <iostream>

typedef int datatype;

class HashTable {
	enum Status { empty, filled, removed };
	struct Item {
		datatype data;
		Status status;
		Item() {
			data = 0;
			status = empty;
		}
	};
	Item* table;
	int size;
	int count;

	int hashFunction(datatype elem, int i) {
		return (firstHash(elem) + i * secondHash(elem)) % size;
	}
	
	int firstHash(datatype elem) {
		return gorner(elem) % size;  
	}

	int secondHash(datatype elem) {
		return gorner(elem) % 7; 
	}

	int gorner(datatype elem) {
		datatype x = elem;
		int result = 1;
		while (x != 0) {
			result = result * (x % 10);
			x = x / 10;
		}
		return result;
	}

	void rehash() {
		if (count > size / 2) {
			Item* oldTable = table;
			size *= 2;
			table = new Item[size];
			count = 0;
			for (int i = 0; i < size/2; i++) {
				if (oldTable[i].status == filled)
					add(oldTable[i].data);
			}
		}
	}

public:
	HashTable() {
		size = 0;
		table = new Item[size];
		count = 0;
	}

	HashTable(int s) {
		size = s;
		table = new Item[size];
		count = 0;
	}

	~HashTable() {
		delete[] table;
	}

	datatype getData(int i) {
		return table[i].data;
	}

	Status getStatus(int i) {
		return table[i].status;
	}

	void add(datatype elem) {
		int i = 0;
		int place = hashFunction(elem, i);
		while (table[place].status == filled) { 
			i++;
			place = hashFunction(elem, i);
		}
		table[place].data = elem;
		table[place].status = filled;
		count++;
		rehash();
	}

	bool search(datatype elem, int &index) {
		int i = 0;
		int place = hashFunction(elem, i);
		bool flag = false;
		while (table[place].status != empty && !flag) {
			if (table[place].status == filled && table[place].data == elem) {
				flag = true;
				index = place;
			}
			i++;
			place = hashFunction(elem, i);
		}
		return flag;
	}

	void remove(datatype elem) {
		int index = 0;
		if (search(elem, index)) {
			table[index].status = removed;
			count--;
		}
	}

	void printHashTable() {
		for (int i = 0; i < size; i++) {
			switch (table[i].status) {
			case empty:
				std::cout << "empty" << "  ";
				break;
			case filled:
				std::cout << "filled" << "  ";
				break;
			case removed:
				std::cout << "removed" << "  ";
				break;
			}
			std::cout << table[i].data << std::endl;
		}
	}
};

//идентификатор как строка, состоящая из букв и цифр
//переделать функцию gorner
