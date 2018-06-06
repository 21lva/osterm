#include "stack.h"
#include "process.h"

stack* init_stack(){
	stack* re = (stack*)malloc(sizeof(stack)*1);
	re->last=NULL;
	return re;
}
void stack_insert(stack* target,process* X){
	element* newel = (element*)malloc(sizeof(element)*1);
	newel->el=X;
	newel->next=target->last;
	target->last=newel;
}
void element_free(element* target){
	target->next=NULL;
}

void stack_pop(stack* target){
	if(target->last==NULL)return;
	element* tmp = target->last->next;
	element_free(target->last);
	target->last=tmp;
}

process* stack_last(stack* target){
	if(target->last==NULL)return NULL;
	return target->last->el;
}
