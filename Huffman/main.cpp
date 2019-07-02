#include <iostream>
#include <fstream>
#include "Sorting.h"
#include "Occurrence.h"
#include "Huffman.h"
#include "ArrayList.h"
#include "ByteArray.h"
int main()
{
	std::ifstream *sourceFile = new std::ifstream("test.txt", std::ifstream::in);
	Huffman huffman;
	huffman.Compress(sourceFile);
	std::ifstream* compressedFile = new std::ifstream("compress.txt", std::ifstream::in);
	huffman.Decompress(compressedFile);
	return 0;
}
