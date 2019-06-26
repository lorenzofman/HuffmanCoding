#include <stdio.h>
#include <stdlib.h>
typedef FILE File;
int *FindOccurrences(File* file)
{
	int *occurrences = malloc(sizeof(int) * 256);
	for (int i = 0; i < 256; i++) occurrences[i] = 0;
	char ch;
	while ((ch = fgetc(file)) != EOF)
	{
		occurrences[(int)ch]++;
	}
	return occurrences;
}

int* FilterOccurrences(int* occurrences)
{
	int count = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i])
		{
			count++;
		}
	}
	int* filtered = malloc(sizeof(int) * 256);
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i])
		{
			filtered[j++] = occurrences[i];
		}
	}
	return filtered;
}
int main()
{
	File* file;
	file = fopen("test.txt", "r");
	int* occurrences = FindOccurrences(file);
	int* filteredOccurrences = FilterOccurrences(occurrences);
	free(occurrences);
}