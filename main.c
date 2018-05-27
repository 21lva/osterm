#include "mainheader.h"

#define FCFS (1)
#define NONP_SJF (2)
#define P_SJF (3)
#define NONP_PRIORITY (4)
#define P_PRIORITY (5)
#define RR (6)


void config(int* IsRandom,int* Alg,int* numP,int* tq){
	printf("Radom process ? Yes(1) or No(0)");
	scanf("%d",IsRandom);
	printf("%d",*IsRandom);
	printf("Choose Algorithm\n1. FCFS\n2. non-preemptive SJF\n3. preemptive SJF\n4. non-preemptive priority\n5. preemptive priority\n6. Round Robin : \n");
	scanf("%d",Alg);
	//printf("%d",*Alg);
	printf("number of process : ");
	scanf("%d",numP);
	//printf("%d",*numP);
	if(*Alg == RR){
		printf("time quantum : ");
		scanf("%d",tq);
	}
	printf("config finished\n");
}

int main(){
	int IsRandom,Alg,numP=3,tq=0,i;
	srand(time(NULL));
	config(&IsRandom,&Alg,&numP,&tq);
	printf("Random : %d ,Algorithm : %d , number of process : %d, time quantum : %d\n",IsRandom,Alg,numP,tq);
	process** parray = (process**)malloc(sizeof(process*)*numP);
	for(i=0;i<numP;i++){
	//	printf("i : %d\n",i);
		parray[i]=make_process(IsRandom);
	}
	Result* result=NULL;

	if(Alg==FCFS)
		result = FCFSA(parray,numP);
	else if(Alg==NONP_SJF)
		result = SJFA(parray,numP,0);
	else if(Alg==P_SJF)
		result = SJFA(parray,numP,1);
	else if(Alg==NONP_PRIORITY)
		result = PRIORITYA(parray,numP,0);
	else if(Alg==P_PRIORITY)
		result = PRIORITYA(parray,numP,1);
	else if(Alg==RR)
		result = RRA(parray,numP,tq);
	GanttChart(result);
	WTTT(result);
	CpuUtilization(result);
	return 0;
}

