#pragma once
#include <fstream>
typedef struct Occurrence
{
	char key;
	int count;
}Occurrence;

Occurrence* FindOccurrences(std::ifstream stream);
Occurrence* FilterOccurrences(Occurrence* occurrences, int* size, int* fileSize);