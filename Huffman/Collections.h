#pragma once
template <class T>
class List
{
	private:
		T* arrayList;
		int count;
		int capacity;
		void EnsureCapacity(int newSize);
	public:
		List();
		void Add(T item);
		void InitializeList();
		int Count();
		T& operator[] (const int idx);
};

template<class T>
List<T>::List()
{
	count = 0;
	capacity = 0;
	arrayList = nullptr;
	InitializeList();
}

template<class T>
inline void List<T>::EnsureCapacity(int newSize)
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

template<class T>
inline void List<T>::Add(T item)
{
	EnsureCapacity(++count);
	arrayList[count - 1] = item;
}

template<class T>
inline void List<T>::InitializeList()
{
	capacity = 1;
	arrayList = new T[1];
}

template<class T>
inline int List<T>::Count()
{
	return count;
}

template<class T>
inline T& List<T>::operator[](const int idx)
{
	if (idx > count || idx < 0)
	{
		throw "IndexOutOfRangeException";
	}
	return arrayList[idx];
}
