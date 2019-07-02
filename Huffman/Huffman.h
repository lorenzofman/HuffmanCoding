#pragma once
#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "ArrayList.h"
#include "Dictionary.h"
#include "ByteArray.h"
class Huffman
{
public:
	void Compress(std::ifstream *);
	void Decompress(std::ifstream *);
};

Dictionary TracebackCode(HuffmanNode* leaf, int height)
{
	ByteArray arrayList;
	int size = height;
	//char* str = new char[size];
	HuffmanNode* from = leaf;
	char c = from->key;
	leaf = leaf->parent;
	while (height-- > 1)
	{
		if (leaf->left == from)
		{
			arrayList.AddBit(false);
			//str[height - 1] = '0';
		}
		else 
		{
			arrayList.AddBit(true);
			//str[height - 1] = '1';
		}
		from = leaf;
		leaf = leaf->parent;
	}
	//str[size - 1] = 0;
	return Dictionary(c, arrayList);
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
	std::ofstream writer = std::ofstream("compress.txt");
	ByteArray byteFile;
	for (int i = 0; i < codes.Count(); i++)
	{
		byteFile.AddByte((char)codes[i].code.position);
		byteFile.AddByte(codes[i].code.list[0]);
		byteFile.AddByte(codes[i].key);
	}
	byteFile.AddByte('\n');
	char ch;
	Dictionary containerVariable;
	Dictionary real;
	int bits = 0;
	while ((ch = stream->get()) != EOF)
	{
		containerVariable.key = ch;
		real = codes.Find(containerVariable);
		for (int i = 0; i < real.code.position; i++)
		{
			char c = real.code.list[i / 8];
			byteFile.AddBit(GetBit(c, i % 8));
		}
		bits++;
	}
	int position = real.code.position + (bits - 1);
	writer.write(reinterpret_cast<const char*>(&position), 4);
	writer.write(byteFile.ToString(), byteFile.list.Count() + 1);
}

void Huffman::Compress(std::ifstream* stream)
{
	int filteredOccurrencesSize, fileSize;
	Occurrence* occurrences = FindTextFileOccurrences(stream);
	Occurrence* filteredOccurrences = FilterOccurrences(occurrences, &filteredOccurrencesSize, &fileSize);
	QuickSort<Occurrence>(filteredOccurrences, filteredOccurrencesSize);
	delete occurrences;
	HuffmanNode* root = CreateHuffmanHeap(filteredOccurrences, filteredOccurrencesSize, fileSize);
	ArrayList<Dictionary> codes;
	ExtractCodesFromHeap(root, &codes, 1);
	stream->clear();
	stream->seekg(0);
	CreateOutputFileFromStreamAndDictionaries(stream, codes);
	delete filteredOccurrences;
}

void BuildTreeFromDictionary()
{

}
void Huffman::Decompress(std::ifstream* stream)
{
	BuildTreeFromDictionary();
}
