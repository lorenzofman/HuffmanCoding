#pragma once
#include <iostream>
#include <fstream>
template <typename T>
class Huffman
{
	void Encode(std::ifstream stream);
	void Decode(std::ifstream stream);
};

template<typename T>
void Huffman<T>::Encode(std::ifstream stream)
{
	/*
	int filteredOccurrencesSize, fileSize;
	Occurrence* occurrences = FindOccurrences(stream);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	//QuickSort(filteredOccurrences, filteredOccurrencesSize);
	free(occurrences);
	CreateGreedyTree(filteredOccurrences, filteredOccurrencesSize, fileSize);
	free(filteredOccurrences);
	*/
}

template<typename T>
void Huffman<T>::Decode(std::ifstream stream)
{
}
