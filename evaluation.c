#include "evaluation.h"
#define FFCFS "./testfile/fcfs.txt"
#define FNSJF "./testfile/nsjf.txt"
#define FPSJF "./testfile/psjf.txt"
#define FNPRI "./testfile/npri.txt"
#define FPPRI "./testfile/ppri.txt"
#define FRR "./testfile/rr.txt"

void GanttChart(Result* result){
	if(result==NULL)printf("fuck1\n");
	if(result->list==NULL)printf("fuck2\n");
	queue* List = result->list;
	qelement* cur=NULL,*pre=NULL;
	int i=0;
	printf("Gantt Chart : ");
	while(queue_first(List)!=NULL){
		cur = queue_first(List);
		if(pre==NULL&&cur->processID==-1)printf("0--[IDLE]-");
		else if(pre==NULL)printf("0--[pid : %d]-",cur->processID);
		else if(cur->processID==pre->processID)printf("-");
		else if(cur->processID!=-1)printf("%d--[pid : %d]-",cur->startT,cur->processID);
		else printf("%d--[IDLE]-",cur->startT);
		i++;
		pre=cur;
		queue_pop(List);
	}
	printf("%d\n",cur->finishedT);
}

void WTTT(Result* result,int Alg){
	stack* Stack = result->finished;
	int ttt=0,count=0,twt=0;//total turnaound time, count, total waiting time
	while(stack_last(Stack)!=NULL){
		process* cur = stack_last(Stack);
		int finT = cur->finishedT,arrT = cur->arrivalT,CB=cur->cpuBT,IB=cur->IOBT;
		printf("process ID :%2d --- waiting time :%3d , turnaround time :%3d\n",cur->processID,finT-arrT-CB-IB,finT-arrT);
		stack_pop(Stack);
		count++;
		twt+=finT-arrT-CB-IB;
		ttt+=finT-arrT;
	}
	printf("\ntotal waiting time :%3d , total turnaround time :%3d\n",twt,ttt);
	printf("average waiting time :%.1lf , average turnaround time :%.1lf\n",(double)twt/count,(double)ttt/count);
	FILE *f;
	if(Alg==1)
		f=fopen(FFCFS,"at");
	else if(Alg==2)
		f=fopen(FNSJF,"at");
	else if(Alg==3)
		f=fopen(FPSJF,"at");
	else if(Alg==4)
		f=fopen(FNPRI,"at");
	else if(Alg==5)
		f=fopen(FPPRI,"at");
	else
		f=fopen(FRR,"at");

	fprintf(f,"%lf %lf %lf\n",(double)twt/count,(double)ttt/count,(result->totaltime-result->idle)/(double)result->totaltime);
	fclose(f);
}

void CpuUtilization(Result* result){
	printf("CPU Utilization : %.2lf\n",(result->totaltime-result->idle)/(double)result->totaltime);
}
