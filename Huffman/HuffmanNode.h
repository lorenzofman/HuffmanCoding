#pragma once
class HuffmanNode
{
public:
	char key;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode* parent;
	HuffmanNode* Merge(HuffmanNode*);
	HuffmanNode(char, HuffmanNode*, HuffmanNode*, int);
	inline bool operator>(const HuffmanNode& rhs) const
	{
		return this->frequency > rhs.frequency;
	}
	inline bool operator<(const HuffmanNode& rhs) const
	{
		return this->frequency < rhs.frequency;
	}
	inline bool operator == (const HuffmanNode& rhs) const
	{
		return this->frequency == rhs.frequency;
	}
};

HuffmanNode::HuffmanNode(char key, HuffmanNode* left, HuffmanNode*right, int frequency)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = nullptr;
	this->frequency = frequency;
}
inline HuffmanNode* HuffmanNode::Merge(HuffmanNode* other)
{
	HuffmanNode* merged = new HuffmanNode(0, this, other, this->frequency + other->frequency);
	this->parent = merged;
	other->parent = merged;
	return merged;
}


