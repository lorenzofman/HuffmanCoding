#include "Occurrence.h"

Occurrence* FindOccurrences(std::ifstream stream)
{
	Occurrence* occurrences = (Occurrence*)malloc(sizeof(Occurrence) * 256);
	if (occurrences == 0)
	{
		return 0;
	}
	for (int i = 0; i < 256; i++)
	{
		occurrences[i].key = i;
	}
	char ch;
	while ((ch = stream.get()) != EOF)
	{
		occurrences[ch].count++;
	}
	return occurrences;
}

Occurrence* FilterOccurrences(Occurrence* occurrences, int* size, int* fileSize)
{
	*size = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i].count)
		{
			(*size)++;
		}
		(*fileSize)++;
	}
	Occurrence* filtered = (Occurrence*)malloc(sizeof(Occurrence) * 256);
	if (filtered == 0) 
	{
		return 0;
	}
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i].count)
		{
			filtered[j++] = occurrences[i];
		}
	}
	return filtered;
}
