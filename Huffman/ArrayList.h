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
	void Add(T*);
	int IndexOf(T);
	T* Remove(T);
	T* RemoveAt(int);
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
void ArrayList<T>::Add(T* item)
{
	EnsureCapacity(++count);
	arrayList[count - 1] = item;
}

template<class T>
int ArrayList<T>::IndexOf(T element)
{
	for (int i = 0; i < count; i++)
	{
		if (element == arrayList[i])
		{
			return i;
		}
	}
	return -1;
}

template<class T>
T* ArrayList<T>::Remove(T element)
{
	return RemoveAt(IndexOf(element));
}
template<class T>
T* ArrayList<T>::RemoveAt(int idx)
{
	if (idx < 0 || idx >= count)
	{
		throw "IndexOutOfRangeException";
	}
	for (int i = idx; i < count - 1; i++)
	{
		arrayList[i] = arrayList[i + 1];
	}
}

template<class T>
T* ArrayList<T>::Find(T element)
{
	return arrayList[IndexOf(element)];
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