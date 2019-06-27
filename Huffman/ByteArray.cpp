#include "ByteArray.h"
bool GetBit(char c, int pos)
{
	char mask = 1 << pos;
	c &= mask;
	return (bool)c;
}
char SetBit(char c, int pos, bool newValue)
{
	char mask = newValue;
	mask <<= pos;
	c |= mask;
	return c;
}
void ByteArray::AddBit(bool bit)
{
	int offset = position % 8;
	if (offset == 0)
	{
		list.Add(0);
	}
	list[offset / 8] = SetBit(list[offset / 8], offset, bit);
	position++;
}

void ByteArray::AddByte(char byte)
{
	for (int i = 0; i < 8; i++)
	{
		AddBit(GetBit(byte,i));
	}
}

ByteArray::ByteArray()
{
	this->position = 0;
	list = ArrayList<char>();
}
