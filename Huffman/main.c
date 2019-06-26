#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include "Ocurrence.h"
int main()
{
	File* file;
	int filteredOccurrencesSize;
	file = fopen("test.txt", "r");
	Occurrence* occurrences = FindOccurrences(file);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize);
	QuickSort(filteredOccurrences, filteredOccurrencesSize);
	free(occurrences);
}