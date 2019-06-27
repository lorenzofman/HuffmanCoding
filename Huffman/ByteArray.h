#pragma once
#include "ArrayList.h"
class ByteArray
{
private:
public:
	int position;
	void AddBit(bool bit);
	void AddByte(char byte);
	char* ToString();
	ArrayList<char> list;
	ByteArray();
};
bool GetBit(char c, int pos);
