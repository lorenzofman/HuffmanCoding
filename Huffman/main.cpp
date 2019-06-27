#include <iostream>
#include <fstream>
#include "Sorting.h"
#include "Occurrence.h"
#include "Huffman.h"
#include "ArrayList.h"
#include "ByteArray.h"
int main()
{
	std::ifstream *testFile = new std::ifstream("test.txt", std::ifstream::in);
	Huffman<char> huffman;
	huffman.Compress(testFile);
	ArrayList<char> c = ArrayList<char>();
	return 0;
}
