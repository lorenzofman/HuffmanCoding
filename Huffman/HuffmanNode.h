#pragma once
template<typename T>
class HuffmanNode
{
public:
	T key;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode* parent;
	void Merge(HuffmanNode*);
	HuffmanNode(T, HuffmanNode*, HuffmanNode*, int);
};

template<typename T>
HuffmanNode<T>::HuffmanNode(T key, HuffmanNode* left, HuffmanNode*right, int frequency)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = nullptr;
	this->frequency = frequency;
}
template<typename T>
inline void HuffmanNode<T>::Merge(HuffmanNode<T>* other)
{
	HuffmanNode<T>* merged = new HuffmanNode<T>(nullptr, this, other, this->frequency + other->frequency);
}


