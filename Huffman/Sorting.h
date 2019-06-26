#ifndef SORTING
#define SORTING
template <typename T>
class Quick
{
private:
	void Sort(T* data, int start, int end);
	public:
	void Sort(T* data, int size);
};
#endif

template<typename T>
inline void Quick<T>::Sort(T* data, int start, int end)
{
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

template<typename T>
inline void Quick<T>::Sort(T* data, int size)
{
	Quick(data, 0, size - 1);
}
