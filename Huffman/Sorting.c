#include "Sorting.h"

void Quick(int* data, int start, int end) {

	int pivot, aux, i, j, mid;

	i = start;
	j = end;

	mid = (int)((i + j) / 2);
	pivot = data[mid];

	do {
		while (data[i] < pivot) i++;
		while (data[j] > pivot) j--;

		if (i <= j) {
			aux = data[i];
			data[i] = data[j];
			data[j] = aux;
			i++;
			j--;
		}
	} while (j > i);

	if (start < j) Quick(data, start, j);
	if (i < end) Quick(data, i, end);
}

void QuickSort(int *data, int size)
{
	Quick(data, 0, size - 1);
}
