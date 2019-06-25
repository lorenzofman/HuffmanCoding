#include "Collections.h"
template<typename T>
void List<T>::Add(T item)
{
	EnsureCapacity(++count);
	arrayList[count - 1] = item;
}
template<typename T>
List<T>::List()
{
	count = 0;
	capacity = 0;
	arrayList = nullptr;
	InitializeList();
}
template<typename T>
void List<T>::InitializeList()
{
	capacity = 1;
	arrayList = new T[1];
}
// Certifies that the size of the array buffer is enough for our data
template<typename T>
void List<T>::EnsureCapacity(int newSize)
{
	if (newSize > capacity)
	{
		int newCapacity = capacity * 2; // Could use fibonacci as well
		T* newArray = new T[newCapacity];
		for (int i = 0; i < capacity; i++)
		{
			newArray[i] = arrayList[i];
		}
		delete arrayList;
		arrayList = newArray;
		capacity = newCapacity;
	}
}

template<typename T>
T *List<T>::operator[](int idx)
{
	if (idx > count || idx < 0)
	{
		throw "IndexOutOfRangeException";
	}
	return &arrayList[idx];
}


