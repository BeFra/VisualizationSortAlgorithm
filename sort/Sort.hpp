/*
 * BubbleSort.hpp
 *
 *  Created on: 06.03.2015
 *      Author: befrank
 */

#ifndef SORT_SORT_HPP_
#define SORT_SORT_HPP_

#include <vector>
using namespace std;
namespace sortAlgo {

void bubble_sort(vector<int> &to_sort);
void selection_sort(vector<int> &to_sort);
void insertion_sort(vector<int> &to_sort);
void quick_sort(vector<int> &to_sort);

}
#endif /* SORT_SORT_HPP_ */