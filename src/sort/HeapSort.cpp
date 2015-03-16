/*
 * HeapSort.cpp
 *
 *  Created on: 15.03.2015
 *      Author: befrank
 */
using namespace std;
#include "Sort.hpp"
namespace sortAlgo {
void heapify(vector<int> &to_sort, int count);
void downheap(vector<int> &to_sort, int length, int index);


void heap_sort(vector<int> &to_sort) {
	heapify(to_sort, to_sort.size());

	int size = to_sort.size();
	while(size > 1) {
		int swap = to_sort[0];
		to_sort[0] = to_sort[size - 1];
		to_sort[size - 1] = swap;
		size--;
		downheap(to_sort, size,0);
	}
}

void downheap(vector<int> &to_sort, int length, int index) {
	int x = to_sort[index];

	while( 2 * index + 1 < length) { /* if to_sort[index] have a child */
		int child_index = 2 * index + 1; /* to_sort[j] is left child of to_sort[index] */
		if( child_index + 1 < length) { /* to_sort have a rigth child */
			if(to_sort[ child_index + 1 ] > to_sort[child_index]) child_index++; /* to_sort[j] is now the highest child */
		}
		if(x >= to_sort[child_index]) break; /* break the loop */
		to_sort[index] = to_sort[child_index]; /* push child to_sort[j] one position bottom up */
		index = child_index;
	}
	to_sort[index] = x;

}

void heapify(vector<int> &to_sort, int count) {

	/* parent index = (count - 1) / 2 */
	for(int i = (count - 2) / 2; i >= 0 ; i--) {
		downheap(to_sort, count, i);
	}
}

}


