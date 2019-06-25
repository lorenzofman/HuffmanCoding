#include "List.h"
#include "String.h"
#include "Huffman.h"
using namespace Collections;
int main()
{
	const char* message = "OurMessage";
	List<char> string = List<char>(message, strlen(message));
	Huffman *huf = new Huffman();
}