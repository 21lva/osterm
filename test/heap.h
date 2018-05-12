#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>


typedef _heap{
	int key;//key value used when sorting
	int* array;
	int last;//+1 of last element
}heap;

heap* init_heap(int key,int size);
void heap_pop(heap* root);
int* heap_first(heap* root);
void heap_insert(heap* root,int newp);


#endif
