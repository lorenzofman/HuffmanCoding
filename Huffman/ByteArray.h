#pragma once
#include "ArrayList.h"
class ByteArray
{
private:
	ArrayList<char> list;
	int position;
public:
	void AddBit(bool bit);
	void AddByte(char byte);
	ByteArray();
};
