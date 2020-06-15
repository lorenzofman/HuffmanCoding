#pragma once

template<typename T>
void QuickSort(T* data, int start, int end)
{
	int i, j, mid;
	T pivot, aux;
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

	if (start < j) QuickSort(data, start, j);
	if (i < end) QuickSort(data, i, end);
}

template<typename T>
void QuickSort(T* data, int size)
{
	QuickSort(data, 0, size - 1);
}
