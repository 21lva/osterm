#include "stack.h"
#include "process.h"

typedef struct _element{
	process* el;
	element* next;
	
}element;
typedef struct _stack{
	element* last;
}stack;

void stack_insert(stack* target,process* X){
	element* newel = (element*)malloc(sizeof(element)*1);
	newel->el=X;
	newel->next=target->last;
	target->last=newel;
}
void element_free(element* target){
	process_free(el);
	target->next=NULL;
	free(target);
}

void stack_pop(stack* target){
	tmp=target->last->next;
	element_free(target->last);
	target->last=tmp;
}

process* stack_last(stack* target){
	return target->last->el;
}
