#pragma once
#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "ArrayList.h"
#include "Dictionary.h"
#include "ByteArray.h"
#include <string>

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

HuffmanNode* Min(ArrayList<HuffmanNode*> ls)
{
	if (ls.Count() == 0)
	{
		throw "Exception";
	}
	HuffmanNode* element = ls[0];
	for (int i = 0; i < ls.Count(); i++)
	{
		if (ls[i]->frequency < element->frequency)
		{
			element = ls[i];
		}
	}
	return element;
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
		HuffmanNode* min = workingNodes.Remove(Min(workingNodes));
		HuffmanNode* min2 = workingNodes.Remove(Min(workingNodes));
		workingNodes.Add(min->Merge(min2));
	}
	return workingNodes[0];
}

void CreateOutputFileFromStreamAndDictionaries(std::ifstream* stream, ArrayList<Dictionary> codes)
{
	std::ofstream writer = std::ofstream("compressed.txt");
	for (int i = 0; i < codes.Count(); i++)
	{
		writer.put(codes[i].code.position);
		writer.put(codes[i].code.list[0]);
		writer.put(codes[i].key);
	}
	writer.put('\n');
	char ch;
	Dictionary containerVariable;
	Dictionary real;
	int bits = 0;
	ByteArray byteFile;
	while ((ch = stream->get()) != EOF)
	{
		containerVariable.key = ch;
		real = codes.Find(containerVariable);
		for (int i = real.code.position - 1; i >= 0; i--)
		{
			char c = real.code.list[i / 8];
			bool bit = GetBit(c, i % 8);
			byteFile.AddBit(bit);
		}
		bits += real.code.position;
	}
	writer.write(reinterpret_cast<const char*>(&bits), 4);
	writer.write(byteFile.ToString(), 1+  byteFile.list.Count());
	writer.close();
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
	stream->close();
	delete filteredOccurrences;
}
ByteArray ReadRest(std::ifstream* stream)
{
	ByteArray firstLine;
	char ch = 0;
	while (*stream >> ch)
	{
		firstLine.AddByte(ch);
	}
	return firstLine;
}
ByteArray ReadFirstLine(std::ifstream* stream)
{
	ByteArray firstLine;
	char ch = 0;
	while(stream->eof() == false)
	{
		stream->get(ch);
		if (ch == '\n') // Not the '\n' character
		{
			return firstLine;
		}
		if (ch != '\r') 
		{
			firstLine.AddByte(ch);
		}
	}
	return firstLine;
}
void AddCodeToTree(HuffmanNode* root, char validDigits, char code, char ascii)
{
	HuffmanNode* current = root;
	for (int i = validDigits - 1; i >= 0 ; i--)
	{
		bool bit = GetBit(code, i);
		if (bit) // Navigate right
		{
			if (current->right == nullptr)
			{
				current->InsertRight(new HuffmanNode('\0', nullptr, nullptr, 0));
			}
			current = current->right;
		}
		else // Navigate left
		{
			if (current->left == nullptr)
			{
				current->InsertLeft(new HuffmanNode('\0', nullptr, nullptr, 0));
			}
			current = current->left;
		}
	}
	current->key = ascii;
}
void ParseDictionary(char *str, HuffmanNode* root)
{
	char codeValidDigits;
	char code;
	char ascii;
	while (*str)
	{
		codeValidDigits = *str++;
		code = *str++;
		ascii = *str++;
		AddCodeToTree(root, codeValidDigits, code, ascii);
	}
}
HuffmanNode* BuildTreeFromDictionary(std::ifstream* stream)
{
	ByteArray firstLine = ReadFirstLine(stream);
	char* str = firstLine.ToString();
	HuffmanNode* root = new HuffmanNode('\0', nullptr, nullptr, 0);
	ParseDictionary(str, root);
	return root;
}
char* Decode(HuffmanNode* tree, std::ifstream* stream, int bits)
{
	ByteArray array = ReadRest(stream);
	ArrayList<char> list;
	HuffmanNode* current = tree;
	for (int i = 0; i < bits; i++)
	{
		bool bit = array.Get(i);
		current = bit ? current->right : current->left;
		if (current->key) // Leaf node
		{
			list.Add(current->key);
			current = tree;
		}
	}
	char* str = new char[list.Count() + 1];
	for (int i = 0; i < list.Count(); i++)
	{
		str[i] = list[i];
	}
	str[list.Count()] = '\0';
	return str;
}
void Huffman::Decompress(std::ifstream* stream)
{
	HuffmanNode* tree = BuildTreeFromDictionary(stream);
	int bitCount;
	stream->read(reinterpret_cast<char*>(&bitCount), sizeof(int));
	char* result = Decode(tree, stream, bitCount);
	std::ofstream of = std::ofstream("decompressed.txt");
	of.write(result, strlen(result));
	of.close();
}
