#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

typedef struct _qelement{
	int processID;
	int startT;
	int finishedT;
	struct _qelement* next;
	struct _qelement* before;	
}qelement;

typedef struct _queue{
	qelement* last;
	qelement* first;
}queue;

queue* init_queue();
void queue_insert(queue* target,int processID,int startT,int finishedT);
void queue_pop(queue* target);
void qelement_free(qelement* target);
qelement* queue_first(queue* target);
void queue_free(queue* target);
#endif
