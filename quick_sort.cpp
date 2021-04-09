#include "quick_sort.h"

void InsertionSort(GraphPoint* a, size_t st, size_t fn) {
	for (size_t i = st; i < fn; i++)
		for (size_t j = i; j > 0 && a[j - 1].value > a[j].value; j--)
			swap(a[j - 1], a[j]);
}

size_t LomutoPartition(GraphPoint* a, size_t st, size_t fn, size_t pivot) {
	swap(a[st + pivot], a[fn]);
	size_t i = st;
	for (size_t j = st; j < fn; j++) {
		// Если (x < pivot) или (x = pivot - для учёта повторений), 
		// но при этом в колонке "x <= pivot" меньше элементов, 
		// чем в "x >= pivot"
		if (a[j].value < a[fn].value or ((a[j].value == a[fn].value) and (i - st < j - i))) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[fn], a[i]);
	return i;
}

GraphPoint* QuickSort(GraphPoint* a, size_t st, size_t fn) {
	size_t limit = 10;
	while (fn - st >= limit) {
		srand(time(0));
		size_t pivot = rand() % (fn - st);
		pivot = LomutoPartition(a, st, fn - 1, pivot);
		// Если левая половина массива меньше...
		if (pivot - st <= fn - pivot - 1) {
			QuickSort(a, st, pivot);
			st = pivot + 1;
		}
		else {
			QuickSort(a, pivot + 1, fn);
			fn = pivot;
		}
	}
	InsertionSort(a, st, fn);
	return a;
}
