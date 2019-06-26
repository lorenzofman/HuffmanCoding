#pragma once
#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "ArrayList.h"
template <typename T>
class Huffman
{
public:
	void Encode(std::ifstream *);
	void Decode(std::ifstream *);
};

void CreateHuffmanHeap(Occurrence* sortedOccurrences, int size, int fileSize)
{
	ArrayList<HuffmanNode> workingNodes;
	for (int i = 0; i < size; i++)
	{
		workingNodes.Add(new HuffmanNode(sortedOccurrences[i].key, nullptr, nullptr, sortedOccurrences[i].count));
	}
	while(workingNodes.Count() > 1)
	{
		HuffmanNode* min = workingNodes.Remove(workingNodes.Min());
		HuffmanNode* min2 = workingNodes.Remove(workingNodes.Min());
		workingNodes.Add(min->Merge(min2));
	}
}

template<typename T>
void Huffman<T>::Encode(std::ifstream* stream)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence* occurrences = FindTextFileOccurrences<T*>(stream);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort<Occurrence>(filteredOccurrences, filteredOccurrencesSize);
	delete occurrences;
	CreateHuffmanHeap(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
