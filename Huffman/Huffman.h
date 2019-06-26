#pragma once
#include <iostream>
#include <fstream>
#include "ArrayList.h"
template <typename T>
class Huffman
{
public:
	void Encode(std::ifstream *);
	void Decode(std::ifstream *);
};

template<typename T>
void CreateGreedyTree(Occurrence<T>* filteredOccurrences, int filteredOccurrencesSize, int fileSize)
{
	ArrayList<Occurrence<T>> list = new ArrayList<Occurrence<T>>(filteredOccurrences, filteredOccurrencesSize);
}

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
	CreateGreedyTree<T>(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
