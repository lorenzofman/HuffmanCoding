#pragma once
#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "ArrayList.h"
#include "Dictionary.h"
template <typename T>
class Huffman
{
public:
	void Compress(std::ifstream *);
	void Decompress(std::ifstream *);
};

Dictionary TracebackCode(HuffmanNode* leaf, int height)
{
	int size = height;
	char* str = new char[size];
	HuffmanNode* from = leaf;
	char c = from->key;
	leaf = leaf->parent;
	while (height-- > 1)
	{
		if (leaf->left == from)
		{
			str[height - 1] = '0';
		}
		else 
		{
			str[height - 1] = '1';
		}
		from = leaf;
		leaf = leaf->parent;
	}
	str[size - 1] = 0;
	return Dictionary(c, str);
}
void ExtractCodesFromHeap(HuffmanNode* root, ArrayList<Dictionary>* codes, int height)
{
	if (root->key != 0)
	{
		codes->Add(TracebackCode(root, height));
	}
	else
	{
		ExtractCodesFromHeap(root->left, codes, height + 1);
		ExtractCodesFromHeap(root->right, codes, height + 1);
	}
}

HuffmanNode* CreateHuffmanHeap(Occurrence* sortedOccurrences, int size, int fileSize)
{
	ArrayList<HuffmanNode*> workingNodes;
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
	return workingNodes[0];
}

void CreateOutputFileFromStreamAndDictionaries(std::ifstream* stream, ArrayList<Dictionary> codes)
{
	
}

template<typename T>
void Huffman<T>::Compress(std::ifstream* stream)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence* occurrences = FindTextFileOccurrences<T*>(stream);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort<Occurrence>(filteredOccurrences, filteredOccurrencesSize);
	delete occurrences;
	HuffmanNode* root = CreateHuffmanHeap(filteredOccurrences, filteredOccurrencesSize, fileSize);
	ArrayList<Dictionary> codes;
	ExtractCodesFromHeap(root, &codes, 1);
	stream->clear();
	stream->seekg(0);
	for (int i = 0; i < codes.Count(); i++)
	{
		std::cout << codes[i].key << " <=>" << codes[i].code << std::endl;
	}
	CreateOutputFileFromStreamAndDictionaries(stream, codes);
	delete filteredOccurrences;
}

template<typename T>
void Huffman<T>::Decompress(std::ifstream* stream)
{

}
