#pragma once
template <class T>
class ArrayList
{
private:
	T** arrayList;
	int count;
	int capacity;
	void EnsureCapacity(int);
public:
	ArrayList();
	ArrayList(const T*, int);
	void Add(T&);
	T* Find(T);
	int Count();
	T& operator[] (int);
};

template<class T>
ArrayList<T>::ArrayList()
{
	count = 0;
	capacity = 1;
	arrayList = new T*[1];
}

template<class T>
ArrayList<T>::ArrayList(const T* array, int size)
{
	*this = ArrayList();
	for (int i = 0; i < size; i++)
	{
		Add(array[i]);
	}
}

template<class T>
void ArrayList<T>::EnsureCapacity(int newSize)
{
	if (newSize > capacity)
	{
		int newCapacity = capacity * 2; // Could use fibonacci as well
		T** newArray = new T*[newCapacity];
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
void ArrayList<T>::Add(T& item)
{
	EnsureCapacity(++count);
	arrayList[count - 1] = &item;
}

template<class T>
T* ArrayList<T>::Find(T element)
{
	for (int i = 0; i < count; i++)
	{
		if (arrayList[i] == element)
		{
			return arrayList[i];
		}
	}
	return nullptr;
}


template<class T>
int ArrayList<T>::Count()
{
	return count;
}

template<class T>
T& ArrayList<T>::operator[](int idx)
{
	if (idx >= count || idx < 0)
	{
		throw "IndexOutOfRangeException";
	}
	return *arrayList[idx];
}