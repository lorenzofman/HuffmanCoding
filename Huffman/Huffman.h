#pragma once
#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
template <typename T>
class Huffman
{
public:
	void Encode(std::ifstream *);
	void Decode(std::ifstream *);
};

template<typename T>
void FindMinValues(HuffmanNode<T>** nodes, HuffmanNode<T>** left, HuffmanNode<T>** right)
{
}

template<typename T>
void CreateHuffmanHeap(Occurrence<T>* sortedFilteredOccurrences, int filteredOccurrencesSize, int fileSize)
{
	/*
	HuffmanNode<T>** nodes = new HuffmanNode<T>*[filteredOccurrencesSize];
	for (int i = 0; i < filteredOccurrencesSize; i++)
	{
		nodes[i] = new HuffmanNode<T>(sortedFilteredOccurrences[i].key, nullptr, nullptr, sortedFilteredOccurrences[i].count);
	}
	int requestedMerges = filteredOccurrencesSize;
	for (int i = 0; i < requestedMerges; i++)
	{
		HuffmanNode<T>* left;
		HuffmanNode<T>* right;
		FindMinValues(nodes, &left, &right);
	}
	*/
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
	CreateHuffmanHeap<T>(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
