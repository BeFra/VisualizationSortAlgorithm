/*
 * BubbleSort.hpp
 *
 *  Created on: 06.03.2015
 *      Author: befrank
 */

#ifndef SORT_SORT_HPP_
#define SORT_SORT_HPP_

using namespace std;
#include <vector>
namespace sortAlgo {

void bubble_sort(vector<int> &to_sort);
void selection_sort(vector<int> &to_sort);
void insertion_sort(vector<int> &to_sort);
void quick_sort(vector<int> &to_sort);
void heap_sort(vector<int> &to_sort);
void merge_sort(vector<int> &to_sort);

}
#endif /* SORT_SORT_HPP_ */
