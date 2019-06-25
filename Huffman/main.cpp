#include "List.h"
#include "String.h"
#include "Huffman.h"
int main()
{
	const char* message = "OurMessage";
	List<char> string = List<char>(message, strlen(message));
	Huffman<char> *huf = new Huffman<char>();
	huf->Compress(string);
}