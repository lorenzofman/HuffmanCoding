#pragma once
class Dictionary
{
public:
	char key;
	char* code;
	Dictionary(char key, char* code)
	{
		this->key = key;
		this->code = code;
	}
	Dictionary()
	{
		key = 0;
		code = nullptr;
	}
};