#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	unsigned long long vertex1;
	unsigned long long vertex2;
	unsigned long long value;
} GraphPoint;

#ifdef __cplusplus
extern "C" {
#endif
	void InsertionSort(GraphPoint* a, size_t st, size_t fn);
	size_t LomutoPartition(GraphPoint* a, size_t st, size_t fn, size_t pivot);
	GraphPoint* QuickSort(GraphPoint* a, size_t st, size_t fn);
#ifdef __cplusplus
}
#endif
