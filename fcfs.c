#include <stdio.h>
#include "process.h"
#include "datastructure.h"

void quicksort(process array[],int left,int right){
	//sort process in order of arrival time
	process pivot = array[(left+right)/2],l=left,r=right,tmp;
	while(l<=r){
		while(array[l].arrivalT<pivot.arrivalT)l++;
		while(array[r].arrivalT>pivot.arrivalT)r--;
		if(l<=r){
			tmp=array[l];
			array[l]=array[r];
			array[r]=tmp;
			l++;
			r--;
		}
	}
	if(left<r)quicksort(array,left,r);
	if(l<right)quicksort(array,l,right);
}

void fcfs(process parray[],int numP){
	queue *ready,*waiting;
	stack done;
	int ttt=0,twt=0;//tt : total turnaround time , wt : total waiting time;
	quicksort(parray);
	/*
	 write here fcfs algorithm
	 */
	//initialize by making ready queue
	ready=make_queue(parray,numP);
	while(!Is_emptyQ(ready)){
		process* runningP=ready.first;
		first->:
	}

}
