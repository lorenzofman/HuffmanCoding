#pragma once
#include "ArrayList.h"
class ByteArray
{
private:
public:
	int position;
	bool Get(int pos);
	void AddBit(bool bit);
	void AddByte(char byte);
	char* ToString();
	char* Print();
	ArrayList<char> list;
	ByteArray();
};
bool GetBit(char c, int pos);
