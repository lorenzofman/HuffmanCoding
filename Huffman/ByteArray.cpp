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
bool ByteArray::Get(int pos)
{
	return GetBit(list[pos / 8], pos % 8);
}
void ByteArray::AddBit(bool bit)
{
	int offset = position % 8;
	if (offset == 0)
	{
		list.Add(0);
	}
	list[position / 8] = SetBit(list[position / 8], offset, bit);
	position++;
}

void ByteArray::AddByte(char byte)
{
	for (int i = 0; i < 8; i++)
	{
		AddBit(GetBit(byte,i));
	}
}
char* ByteArray::ToString()
{
	char* str = new char[list.Count() + 1];
	for (int i = 0; i < list.Count(); i++)
	{
		str[i] = list[i];
	}
	str[list.Count()] = '\0';
	return str;
}
ByteArray::ByteArray()
{
	this->position = 0;
	list = ArrayList<char>();
}
