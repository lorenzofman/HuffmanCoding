#pragma once
#include <iostream>
#include <fstream>
template <typename T>
class Huffman
{
public:
	void Encode(std::ifstream *stream);
	void Decode(std::ifstream *stream);
};

template<typename T>
void Huffman<T>::Encode(std::ifstream* stream)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence<T>* occurrences = FindOccurrences<T>(stream);
	Occurrence<T>* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort<Occurrence<T>>(filteredOccurrences, filteredOccurrencesSize);
	for (int i = 0; i < filteredOccurrencesSize; i++)
	{
		std::cout << filteredOccurrences[i].key << "  " << filteredOccurrences[i].count << std::endl;
	}
	delete occurrences;
	//CreateGreedyTree(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
