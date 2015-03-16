/*
 * MergeSort.cpp
 *
 *  Created on: 16.03.2015
 *      Author: befrank
 */

#include "Sort.hpp"
using namespace std;

namespace sortAlgo {
void merge_sort(vector<int> &to_sortA, int li, int re, vector<int> &to_sortB);
void merge(vector<int> &to_sortA, int aLi, int aRe,vector<int> &to_sortB, int bLi, int bRe, vector<int> &to_sortC, int cLi );

void merge_sort(vector<int> &to_sort) {

	vector<int> tmp(to_sort);
	merge_sort(to_sort, 0, to_sort.size() - 1, tmp);
}

void merge_sort(vector<int> &to_sortA, int li, int re,
		        vector<int> &to_sortB) {
	if(re > li) {
		/* divide */
		int m = (li + re) / 2;

		/* conquer */
		merge_sort(to_sortB, li,m, to_sortA);
		merge_sort(to_sortB, m + 1, re, to_sortA);

		/* merge */
		 merge(to_sortB, li, m, to_sortB, m + 1, re, to_sortA, li);
	}
}

void merge(vector<int> &to_sortA, int aLi, int aRe, vector<int> &to_sortB, int bLi, int bRe, vector<int> &to_sortC, int cLi ) {
/* merge sortet array to_sortA[aLi],...,to_sortA[aRe] and to_sortB[bLi],...,to_sortB[bRe] and write result to c[cLi],.... */
	int i = aLi;
	int j = bLi;
	int k = cLi;
	while (i <= aRe && j <= bRe)
			if (to_sortA[i] <= to_sortB[j])
				to_sortC[k++] = to_sortA[i++];
			else
				to_sortC[k++] = to_sortB[j++];
	if (j == bRe+1) // b zu Ende
		while (i <= aRe)
			to_sortC[k++] = to_sortA[i++];
	else // a zu Ende
		while (j <= bRe)
			to_sortC[k++] = to_sortB[j++];
}
}

