#ifndef STACK_H
#define STACK_H

#include "process.h"

typedef struct _element{
	process* el;
	element* next;
	
}element;

typedef struct _stack{
	element* last;
}stack;

void stack_insert(stack* target,process* X);
void element_free(element* target);
void stack_pop(stack* target);
process* stack_last(stack* target);
#endif
