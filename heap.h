#ifndef HEAP_H
#define HEAP_H

#include "process.h"

#define GETTINGT 1
#define	PRIORITY 2
#define LEFTCPU 3
#define SLEFTCPU 4

typedef _heap{
	int key;//key value used when sorting
	process** array;
	int last;//+1 of index last element
}heap;

heap* init_heap(int key,int size);
void heap_pop(heap* root);
process* heap_first(heap* root);
void heap_insert(heap* root,process* newp);


#endif
