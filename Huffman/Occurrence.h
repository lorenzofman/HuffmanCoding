#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class Occurrence
{
public:
	T key;
	int count;
	inline bool operator>(const Occurrence<T>& someOccurrence) const;
	inline bool operator<(const Occurrence<T>& someOccurrence) const;
}; template<typename T>

inline Occurrence<T>* FindOccurrences(std::ifstream *stream) 
{
	Occurrence<T>* occurrences = (Occurrence<T>*)malloc(sizeof(Occurrence<T>) * 256);
	if (occurrences == 0)
	{
		return 0;
	}
	for (int i = 0; i < 256; i++)
	{
		occurrences[i].key = i;
		occurrences[i].count = 0;
	}
	char ch;
	while ((ch = stream->get()) != EOF)
	{
		occurrences[ch].count++;
	}
	return occurrences;
}

template<typename T>
inline Occurrence<T>* FilterOccurrences(Occurrence<T>* occurrences, int* size, int* fileSize)
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

template<typename T>
inline bool Occurrence<T>::operator>(const Occurrence<T>& someOccurrence) const
{
	return count > someOccurrence.count;
}

template<typename T>
inline bool Occurrence<T>::operator<(const Occurrence<T>& someOccurrence) const
{
	return count < someOccurrence.count;
}
