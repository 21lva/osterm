#ifndef HEAP_H
#define HEAP_H

#include "process.h"

typedef _heap{
	int key;//key value used when sorting
	process** array;
	int last;//+1 of last element
}heap;

heap* init_heap(int key,int size);
void heap_pop(heap* root);
process* heap_first(heap* root);
void heap_insert(process* newp);


#endif
