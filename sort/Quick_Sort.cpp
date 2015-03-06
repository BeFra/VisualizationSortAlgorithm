#include <vector>
#include "Sort.hpp"
using namespace std;

namespace sortAlgo {

static int partition(vector<int> &to_sort, int left, int right);
static int findeMedian(vector<int> &to_sort, int left, int right);
static void quickSort(vector<int> &to_sort, int left, int right);

static int partition(vector<int> &to_sort, int left, int right) {
	/* if the list is sorted the algo performs better with a median
	 than using the element of the right side int v = to_sort[right];*/
	int median = findeMedian(to_sort, left, right);
	int pivot = to_sort[median];
	to_sort[median] = to_sort[right];
	to_sort[right] = pivot;

	/* Pivotelement */
	int i = left - 1;
	int j = right;
	while (true) {
		do
			i++;
		while (to_sort[i] < pivot);
		do
			j--;
		while (j >= left && to_sort[j] > pivot);
		if (i >= j)
			break;
		/* swap to_sort[i] and to_sort[j] */
		int t = to_sort[i];
		to_sort[i] = to_sort[j];
		to_sort[j] = t;
	}
	/* swap Pivotelement to_sort[right] und to_sort[i] */
	to_sort[right] = to_sort[i];
	to_sort[i] = pivot;
	return i;
}

static int findeMedian(vector<int> &to_sort, int left, int right) {
	int middle = (left + right) / 2;
	int median;

	if (to_sort[left] > to_sort[middle]) {
		if (to_sort[middle] > to_sort[right]) {
			median = middle;
		} else if (to_sort[right] > to_sort[left]) {
			median = right;
		} else {
			median = left;
		}
	} else {
		if (to_sort[middle] < to_sort[right]) {
			median = middle;
		} else if (to_sort[right] < to_sort[left]) {
			median = left;
		} else {
			median = right;
		}
	}
	return median;
}

static void quickSort(vector<int> &to_sort, int left, int right) {
	// sort subfield to_sort[left], to_sort[left+1], ..., to_sort[right].
	if (right > left) {
		/* divide  step */
		int i = partition(to_sort, left, right);
		/* conquer step */
		quickSort(to_sort, left, i - 1);
		quickSort(to_sort, i + 1, right);
	}
}

void quick_sort(vector<int> &to_sort) {
	if(to_sort.empty()) {
		return;
	}
	quickSort(to_sort, 0, to_sort.size() - 1);
}

}
