/*
 * InsertionSort.cpp
 *
 *  Created on: 06.03.2015
 *      Author: befrank
 */

#include "Sort.hpp"
using namespace std;

namespace sortAlgo {

void insertion_sort(vector<int> &to_sort) {
	if (to_sort.empty()) {
		return;
	}
	int size = to_sort.size();

	for (int i = 1; i < size; i++) {
		int select = to_sort[i];
		int j = i;

		while (j > 0 && to_sort[j - 1] > select) {

			to_sort[j] = to_sort[j - 1];
			j -= 1;
		}
		to_sort[j] = select;
	}
}
}

