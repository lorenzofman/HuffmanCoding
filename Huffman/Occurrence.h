#pragma once
template <class T>
class Occurrence
{
	public:
		T *key;
		int count;
		Occurrence();
		Occurrence(T key, int count);
		void CountOccurrence();
		bool operator == (Occurrence const &rhs);
};
template<class T>
Occurrence<T>::Occurrence()
{
	key = nullptr;
	count = 0;
}
template <class T>
Occurrence<T>::Occurrence(T key, int count)
{
	this->key = &key;
	this->count = count;
}

template <class T>
void Occurrence<T>::CountOccurrence()
{
	count++;
}

template <class T>
bool Occurrence<T>::operator==(Occurrence<T> const& rhs)
{
	return this->key == rhs.key;
}

