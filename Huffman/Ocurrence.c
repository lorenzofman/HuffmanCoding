#include "Ocurrence.h"

Occurrence* FindOccurrences(File* file)
{
	Occurrence* occurrences = (Occurrence*)malloc(sizeof(Occurrence) * 256);
	for (int i = 0; i < 256; i++)
	{
		occurrences[i].key = i;
	}
	char ch;
	while ((ch = fgetc(file)) != EOF)
	{
		occurrences[ch].count++;
	}
	return occurrences;
}

Occurrence* FilterOccurrences(Occurrence* occurrences, int* size)
{
	*size = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i].count)
		{
			(*size)++;
		}
	}
	Occurrence* filtered = (Occurrence*)malloc(sizeof(Occurrence) * 256);
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
