#include "queue.h"


queue* init_queue(){
	queue* re = (queue*)malloc(sizeof(queue)*1);
	qelement* root = (qelement*)malloc(sizeof(qelement)*1);
	root->processID=-1;
	root->startT=-1;
	root->finishedT=-1;
	root->next=NULL;
	root->before=NULL;
	re->last=root;
	re->first=root;
}

void queue_insert(queue* target,int processID,int startT,int finishedT){
	qelement* newel = (qelement*)malloc(sizeof(qelement)*1);
	newel->processID=processID;
	newel->startT = startT;
	newel->finishedT = finishedT;
	target->last->next=newel;
	newel->before=target->last;
	newel->next=NULL;
	target->last=newel;
}
void qelemnt_free(qelement* target){
	target->next=NULL;
	target->before=NULL;
	free(target);
}
void queue_pop(queue* target){
	qelement *tmp = target->first->next;
	target->first->next = tmp->next;
	tmp->next->before = target->first;
	qelement_free(tmp);
}
void queue_free(queue* target){
	while(queue_first(target)!=NULL){
		queue_pop(target);
	}
	free(target);
}

qelement* queue_first(queue* target){
	return target->first->next;
}
