#include "Sorting.h"
#include "Occurrence.h"
#include "Huffman.h"
#include <iostream>
#include <fstream>
int main()
{
	std::ifstream *testFile = new std::ifstream("test.txt", std::ifstream::in);
	Huffman<char> huffman;
	huffman.Encode(testFile);
	return 0;
}