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
template<typename T>
void PrintHeap(HuffmanNode<T> *root)
{
	int space = 3;
	int COUNT = 1;
	// Base case  
	if (root == nullptr)
		return;

	// Process right child first  
	PrintHeap(root->right);

	// Print current node after space  
	// count  
	std::cout << std::endl;
	std::cout << *(root->key) << "\n";

	// Process left child  
	PrintHeap(root->left);
}
template<typename T>
void CreateHuffmanHeap(Occurrence<T>* sortedOccurrences, int size, int fileSize)
{
	ArrayList<HuffmanNode<T>> workingNodes;
	for (int i = 0; i < size; i++)
	{
		workingNodes.Add(new HuffmanNode<T>(sortedOccurrences[i].key, nullptr, nullptr, sortedOccurrences[i].count));
	}
	while(workingNodes.Count() > 1)
	{
		HuffmanNode<T>* min = workingNodes.Remove(workingNodes.Min());
		HuffmanNode<T>* min2 = workingNodes.Remove(workingNodes.Min());
		workingNodes.Add(min->Merge(min2));
	}
	PrintHeap(&workingNodes[0]);
}

template<typename T>
void Huffman<T>::Encode(std::ifstream* stream)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence<T>* occurrences = FindTextFileOccurrences<T*>(stream);
	Occurrence<T>* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort<Occurrence<T>>(filteredOccurrences, filteredOccurrencesSize);
	delete occurrences;
	CreateHuffmanHeap<T>(filteredOccurrences, filteredOccurrencesSize, fileSize);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decode(std::ifstream* stream)
{
}
