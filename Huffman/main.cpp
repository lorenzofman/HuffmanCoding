#include "Collections.h"
#include "main.h"
#include <iostream>
int main()
{
	List<int> list;
	list.Add(3);
	list.Add(4);
	list.Add(2);
	list.Add(10);
	list[3] = 3;
	for (int i = 0; i < list.Count(); i++)
	{
		std::cout << list[i] << std::endl;
	}
}