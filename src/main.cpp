#include "sort/Sort.hpp"
#include <iostream>

int main() {
	vector<int> toSort = { 7,5,1,8,3,9,6,4,2};
	vector<int>::iterator IntIterator;

	sortAlgo::bubble_sort(toSort);
	for(IntIterator = toSort.begin(); IntIterator != toSort.end(); IntIterator++) {
		cout << *IntIterator <<endl;
	}
	return 0;
}
