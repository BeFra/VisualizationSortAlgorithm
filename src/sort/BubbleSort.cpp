using namespace std;
#include "Sort.hpp"
#include "../draw/draw.hpp"
namespace sortAlgo {

void bubble_sort(vector<int> &to_sort) {
	if (to_sort.empty()) {
		return;
	}
	draw(to_sort);
	bool swapped = false;
	int size = to_sort.size();
	do {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (to_sort[i] > to_sort[i + 1]) {
				int tmp = to_sort[i];
				to_sort[i] = to_sort[i + 1];
				to_sort[i + 1] = tmp;
				swapped = true;
			}
			draw(to_sort);
		}
		size -= 1;
	} while (swapped == true);
}
}
