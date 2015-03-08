/*
 * SelectionSort.cpp
 *
 *  Created on: 06.03.2015
 *      Author: befrank
 */
#include <vector>
#include "Sort.hpp"

using namespace std;

namespace sortAlgo {

void selection_sort(vector<int> &to_sort) {
	if (to_sort.empty()) {
		return;
	}
	int size = to_sort.size();
	int left = 0;
	int min;
	do {
		min = left;
		for (int i = left + 1; i < size; i++) {
			if (to_sort[i] < to_sort[min]) {
				min = i;
			}
		}
		int tmp = to_sort[min];
		to_sort[min] = to_sort[left];
		to_sort[left] = tmp;
		left += 1;
	} while (left < size);
}
}
