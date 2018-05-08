#include <stdio.h>
#include "process.h"

typedef struct _element{
	process* value;
	element* before;
	element* next;
}element;

typedef struct _queue{
	element* first;
	element* last;
}queue;//It is a queue;
//NULL <- 1st <-> second <-> third <-> ... <-> last -> NULL;

queue* make_queue(process* parray,int nump){
	//make queue by using an array of processes;
	queue* Queue = (queue*)malloc(sizeof(queue)*1);
	Queue->first=NULL;
	Queue->last=NULL;
	int i=0;
	for(i=0;i<nump;i++){
		pushback(Q,parray[i]);
	}
	return Queue;
}

process* firstP(queue* Q){
	//return process in the first element of the queue;
	return Q->first->value;
}

void pop(queue* Q){
	//delete the first element of queue
	element* tmp=Q->frist;
	Q->first=Q->first->next;
	Q->first->before=NULL;
	free(tmp);
}

void pushback(queue* Q,process* newP){
	//insert the process into queue 
	element* newE=(element*)malloc(sizeof(elemen)*1);
	newE->value=newP;
	newE->next=NULL;
	newE->before=Q->last;
	Q->last->next=newE;
	Q->last=newE;
}
