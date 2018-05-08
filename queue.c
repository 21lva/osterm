#include "queue.h"
#include <stdio.h?>
#include <time.h>

srand(time(NULL));

queue* init(int type,int time){
	queue* newQ = (queue*)malloc(sizeof(queue)*1);
	newQ->type=type;
	newQ->time=time;
	newQ->next=NULL;
	return newQ;
}

void pop(queue* seq){
	if(seq!=NULL){
		queue* tmp = seq->next;
		free(seq);
		seq=tmp;
	}
}

queue* first(queue* seq){
	return seq;
}

void insert(queue* seq, queue* target){
	queue *cur;
	for(cur=seq;cur->next!=NULL;cur=cur->next);
	cur->next=target;
}

void make_queue(queue* root,int cpuBT,int IOBT,int Is_random){
	if(Is_random){
		//randomly determined job schedule
		int cbt=cpuBT,ibt=IOBT;
		root = init(1,1);
		cbt--;
		while(cbt>0&&ibt>0){
			if((rand()%1)==0){
				//use cpu time
				int time_used=rand()%cbt+1;
				insert(root,init(1,time_used));
				cbt-=time_used;
			}
			else{
				//use I/O time
				int time_used=rand()%ibt+1;
				insert(root,init(0,time_used));
				ibt-=time_used;
			}
		}
		if(cbt>0)insert(root,init(1,cbt));
		if(ibt>0)insert(root,init(0,ibt));
	}
	else{
		//unrandomly. scanf is used
		int cbt=cpuBT,ibt=IOBT,typetmp,valuetmp;
		root = init(1,1);
		while(cbt>0&&ibt>0){
			printf("cpu burst (1) or I/O burst (0) : ");
			scanf("%d",&typetmp);
			printf("time used between 0 to %d: ",(typetmp==1)? cbt:ibt);
			scanf("%d",&valuetmp);
			if(valuetmp>((typetmp==1)? cbt:ibt)){
				printf("the value is over\n");
				continue;
			}
			insert(root,init(typetmp,valuetmp);
			if(typetmp==1)cbt-=valuetmp;
			else ibt-=valuetmp;
		}
		if(cbt>0)insert(root,init(1,cbt));
		if(ibt>0)insert(root,init(0,ibt));
	}
}
