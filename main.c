#include "mainheader.h"

#define FCFS 1
#define NONP_SJF 2
#define P_SJF 3
#define NONP_PRIORITY 4
#define P_PRIORITY 5
#define RR 6


int config(int* IsRandom,int* Alg,int* numP,int* tq){
	printf("Radom process ? Yes(1) or No(0)");
	scanf("%d",IsRandom);
	printf("Choose Algorithm\n1. FCFS\n2. non-preemptive SJF\n3. preemptive SJF\n4. non-preemptive priority\n5. preemptive priority\n6. Round Robin\n");
	scanf("%d",Alg);
	printf("number of process : ");
	scanf("%d",numP);
	if(*Alg == RR){
		printf("time quantum : ");
		scanf("%d",tq);
	}
}

int main(){
	int IsRandom,Alg,numP,tq,i;
	config(&IsRandom,&Alg,&numP,&tq);
	process** parray = (process**)malloc(sizeof(process*)*numP);
	for(i=0;i<numP;i++){
		parray[i]=make_process(IsRandom);
	}
	Result* result=NULL;
	
	if(Alg==FCFS)
		result = FCFS(parray,numP);
	else if(Alg==NONP_SJF)
		result = SJF(parray,numP,0);
	else if(Alg=P_SJF)
		result = SJF(parray,numP,1);
	else if(Alg=NONP_PRIORITY)
		result = PRIORITY(parray,numP,0);
	else if(Alg=P_PRIORITY)
		result = PRIORITY(parray,numP,1);
	else if(Alg=RR)
		result = RR(parray,numP,tq);
	GanttChart(result);
	WTTT(result);
	CpuUtilization(result);

	return 0;
}

