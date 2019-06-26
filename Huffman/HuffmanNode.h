#pragma once
template<typename T>
class HuffmanNode
{
public:
	T* key;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode* parent;
	HuffmanNode<T>* Merge(HuffmanNode*);
	HuffmanNode(T*, HuffmanNode*, HuffmanNode*, int);
	inline bool operator>(const HuffmanNode<T>& rhs) const
	{
		return this->frequency > rhs.frequency;
	}
	inline bool operator<(const HuffmanNode<T>& rhs) const
	{
		return this->frequency < rhs.frequency;
	}
	inline bool operator == (const HuffmanNode<T>& rhs) const
	{
		return this->frequency == rhs.frequency;
	}
};

template<typename T>
HuffmanNode<T>::HuffmanNode(T* key, HuffmanNode* left, HuffmanNode*right, int frequency)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->frequency = frequency;
}
template<typename T>
inline HuffmanNode<T>* HuffmanNode<T>::Merge(HuffmanNode<T>* other)
{
	HuffmanNode<T>* merged = new HuffmanNode<T>(nullptr, this, other, this->frequency + other->frequency);
	return merged;
}


