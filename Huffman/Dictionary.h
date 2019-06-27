#pragma once
#include "ByteArray.h"
class Dictionary
{
public:
	char key;
	ByteArray code;
	bool operator== (Dictionary& other)
	{
		return this->key == other.key;
	}
	Dictionary(char key, ByteArray code)
	{
		this->key = key;
		this->code = code;
	}
	Dictionary()
	{
		key = 0;
		code = ByteArray();
	}
};