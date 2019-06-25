#pragma once
#include "Collections.h"
#include "Occurrence.h"
#include <iostream>
template <class T>
class Huffman
{
	private:
		List<Occurrence<T>>* occurrences;
		void CountOccurrences(List<T> source);
	public:
		void Compress(List<T> source);
		void Decompress();
};
template<class T>
void Huffman<T>::CountOccurrences(List<T> source)
{
	occurrences = new List<Occurrence<T>>();
	for (int i = 0; i < source.Count(); i++)
	{
		Occurrence<T> key = Occurrence<T>(source[i],0);
		Occurrence<T> *occurrence = (occurrences->Find(key));
		if (occurrence != nullptr)
		{
			occurrence->CountOccurrence();
		}
		else 
		{
			occurrences->Add(*occurrence);
		}
	}
	for (int i = 0; i < occurrences->Count(); i++)
	{
		//std::cout << occurrences[i].key;
	}
}

template<class T>
void Huffman<T>::Compress(List<T> source)
{
	CountOccurrences(source);
}
template<class T>
void Huffman<T>::Decompress()
{

}
