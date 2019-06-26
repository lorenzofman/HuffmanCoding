#ifndef OCCURRENCE
#define OCCURRENCE
#include <stdio.h>
#include <stdlib.h>
typedef struct Occurrence
{
	char key;
	int count;
}Occurrence;

typedef FILE File;
Occurrence* FindOccurrences(File* file);
Occurrence* FilterOccurrences(Occurrence* occurrences, int* size);
#endif