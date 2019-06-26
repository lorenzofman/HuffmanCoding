#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class Occurrence
{
	T key;
	int count;
	Occurrence<T>* FindOccurrences(std::ifstream stream);
	Occurrence<T>* FilterOccurrences(Occurrence* occurrences, int* size, int* fileSize);
};

template<typename T>
inline Occurrence<T>* Occurrence<T>::FindOccurrences(std::ifstream stream)
{
	Occurrence<T>* occurrences = (Occurrence<T>*)malloc(sizeof(Occurrence<T>) * 256);
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

template<typename T>
inline Occurrence<T>* Occurrence<T>::FilterOccurrences(Occurrence<T>* occurrences, int* size, int* fileSize)
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
	Occurrence<T>* filtered = (Occurrence<T>*)malloc(sizeof(Occurrence<T>) * 256);
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
