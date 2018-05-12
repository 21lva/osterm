#include "evaluation.h"

void GanttChart(Result* result){
	queue* List = result->list;
	qelement* cur,*pre=NULL;
	int i=0;
	while(queue_first(List)!=NULL){
		cur = queue_first(List);
		if(pre!=NULL&&cur->processID==pre->processID)printf("~");
		else printf("%d~~ID : %d~",i,cur->processID);
		i++;
		pre=cur;
		queue_pop(List);
	}
	printf("\n");
}

void WTTT(Result* result){
	stack* Stack = result->finished;
	int ttt=0,count=0,twt=0;//total turnaound time, count, total waiting time
	while(stack_last(Stack)!=NULL){
		process* cur = stack_last(Stack);
		int finT = cur->finishedT,arrT = cur->arrivalT,CB=cur->cpuBT,IB=cur->IOBT;
		printf("process ID :%2d --- waiting time :%3d , turnaround time :%3d",cur->processID,finT-arrT-CB-IB,finT-arrT);
		stack_pop(Stack);
		count++;
		twt+=finT-arrT-CB-IB;
		ttt+=finT-arrT;
	}
	printf("\ntotal waiting time :%3d , total turnaround time :%3d\n",twt,ttt);
	printf("average waiting time :%.1lf , average turnaround time :%.1lf\n",(double)twt/count,(double)ttt/count);
}

void CpuUtilization(Result* result){
	printf("CPU Utilization : %.2lf\n",(result->totaltime-result->idle)/(double)result->totaltime);
}
