#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue{
	int type;//if this is CPU burst, then type is 1. Otherwise 0
	int time;
	queue* next;
}queue;

queue* init(int type,int time);
void pop(queue* seq);
queue* first(queue* seq);
void insert(queue* seq,queue* target);
void make_queue(int Is_random);


#endif
