#include "Huffman.h"
#include "Occurrence.h"
#include "Sorting.h"

void CreateGreedyTree(Occurrence* sortedOccurrences, int sortedOccurrencesSize, int fileSize)
{
	int sum = 0;
}

void Encode(File* file)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence* occurrences = FindOccurrences(file);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort(filteredOccurrences, filteredOccurrencesSize);
	free(occurrences);
	CreateGreedyTree(filteredOccurrences, filteredOccurrencesSize, fileSize);
	free(filteredOccurrences);
}

void Decode(File* file)
{
}
