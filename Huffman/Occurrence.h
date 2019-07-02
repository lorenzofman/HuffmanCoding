#pragma once
#include <iostream>
#include <fstream>

class Occurrence
{
public:
	char key;
	int count;
	inline bool operator>(const Occurrence&) const;
	inline bool operator<(const Occurrence&) const;
	inline bool operator == (const Occurrence&) const;
};
Occurrence* FindTextFileOccurrences(std::ifstream *stream) 
{
	Occurrence* occurrences = new Occurrence[256];
	for (int i = 0; i < 256; i++)
	{
		occurrences[i].key = i;
		occurrences[i].count = 0;
	}
	char ch;
	while ((ch = stream->get()) != EOF)
	{
		occurrences[ch].count++;
	}
	return occurrences;
}

Occurrence* FilterOccurrences(Occurrence* occurrences, int* size, int* fileSize)
{
	*size = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i].count)
		{
			(*size)++;
		}
		(*fileSize)++;
	}
	Occurrence* filtered = new Occurrence[256];
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		if (occurrences[i].count)
		{
			filtered[j++] = occurrences[i];
		}
	}
	return filtered;
}

inline bool Occurrence::operator>(const Occurrence& someOccurrence) const
{
	return count > someOccurrence.count;
}

inline bool Occurrence::operator<(const Occurrence& someOccurrence) const
{
	return count < someOccurrence.count;
}

inline bool Occurrence::operator==(const Occurrence& occurrence) const
{
	return(this->key == occurrence.key);
}
