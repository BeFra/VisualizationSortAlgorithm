/*
 * HashDicitionary.cpp
 *
 *  Created on: 18.03.2015
 *      Author: befrank
 */

#include "HashDictionary.hpp"

#define INIT_SIZE 7
using namespace std;

namespace collection {

HashDictionary::HashDictionary() :
		size_(0), table(INIT_SIZE) {
}

HashDictionary::~HashDictionary() {
}

void HashDictionary::insert(const int key, const int value) {
	int count = 0, adr = 0;
	if(( adr = searchAdr(key) != -1)) {
		table[adr].value = value;
		return;
	}

	do {
		adr = getHash(key, count);
		count++;
	} while (table[adr].state != Entry::State::EMPTY
			&& table[adr].state != Entry::State::ERASED);

	table[adr].key = key;
	table[adr].value = value;
	table[adr].state = Entry::State::USED;
	size_++;
}

int HashDictionary::getHash(const int key, const int count) const {
	return (key + count % INIT_SIZE);
}

int HashDictionary::searchAdr(const int key) const {
	int adr = 0, count = 0;
	do {
		adr = getHash(key, count);
		count++;
	} while (table[adr].state != Entry::State::EMPTY && table[adr].key != key);

	if (table[adr].state != Entry::State::EMPTY) {
		return adr;
	} else {
		return -1;
	}
}

bool HashDictionary::contains(const int key) {
	int adr = 0;
	if ((adr = searchAdr(key)) != -1) {
		return true;
	}
	return false;
}

void HashDictionary::remove(const int key) {
	int adr = 0;
	if ((adr = searchAdr(key)) != -1) {
		table[adr].state = Entry::State::ERASED;
		size_--;
	}
}

int HashDictionary::getValue(const int key)  {
	int adr = 0;
	if ((adr = searchAdr(key)) != -1) {
		return table[adr].value;
	} else {
		return - 1; //throw logic_error("Element not found!");
	}
}

int HashDictionary::size() {
	return size_;
}

bool HashDictionary::empty() {
	return size_ == 0;
}

void HashDictionary::clear() {
	table.clear();
	table.resize(INIT_SIZE);
	size_ = 0;
}

}
