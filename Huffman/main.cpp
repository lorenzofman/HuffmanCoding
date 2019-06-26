#include "Sorting.h"
#include "Occurrence.h"
#include "Huffman.h"
#include "ArrayList.h"
#include <iostream>
#include <fstream>
int main()
{
	std::ifstream *testFile = new std::ifstream("test.txt", std::ifstream::in);
	Huffman<char> huffman;
	huffman.Encode(testFile);
	ArrayList<char> c = ArrayList<char>();
	return 0;
}
