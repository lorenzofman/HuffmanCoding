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
	delete occurrences;
	//CreateGreedyTree(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
