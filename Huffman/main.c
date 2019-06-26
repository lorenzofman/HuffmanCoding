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
int main()
{
	File* file;
	file = fopen("test.txt", "r");
	int* occurrences = FindOccurrences(file);
	for (int i = 0; i < 256; i++)
	{
		printf("%c (%i)\n",(char) i, occurrences[i]);
	}
}