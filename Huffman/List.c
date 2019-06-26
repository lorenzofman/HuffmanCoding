#include "List.h"
#include <stdlib.h>
void EnsureCapacity(List *list)
{
	if (list->count > list->capacity)
	{
		list->capacity *= 2;
		int* newArray = realloc(list->arrayList, list->capacity * sizeof(int));
		if (newArray == 0)
		{
			return 0;
		}
		list->arrayList = newArray;
	}
}
List* CreateList()
{
	List* list = (List*)malloc(sizeof(List));
	if (list == 0)
	{
		return 0;
	}
	list->arrayList = (int*)malloc(sizeof(int));
	list->capacity = 1;
	list->count = 0;
}

void ListAdd(List* list, int value)
{
	list->count++;
	EnsureCapacity(list);
	list->arrayList[list->count] = value;
}

void ListDelete(List* list, int value)
{
	int i;
	for (i = 0; i < list->count; i++)
	{
		if (list->arrayList[i] == value)
		{
			break;
		}
	}
	for (; i < list->count - 1; i++)
	{
		list->arrayList[i] = list->arrayList[i + 1];
	}
	list->count--;
}
