#ifndef LIST
#define LIST
typedef struct List
{
	int * arrayList;
	int count;
	int capacity;
}List;
List* CreateList();
void ListAdd(List* list, int value);
void ListDelete(List* list, int value);
#endif