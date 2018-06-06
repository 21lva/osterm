#include "mainheader.h"

#define FCFS (1)
#define NONP_SJF (2)
#define P_SJF (3)
#define NONP_PRIORITY (4)
#define P_PRIORITY (5)
#define RR (6)
char algarr[6][40]={"FCFS","non-preemptive-SJF","preemptive-SJF","non-preemptive-Priority","preemptive-Priority","Round-Robin"};

void config(int* IsRandom,int* Alg,int* numP,int* tq){
	printf("Radom process ? Yes(1) or No(0)");
	scanf("%d",IsRandom);
	printf("%d",*IsRandom);
	printf("Choose Algorithm\n1. FCFS\n2. non-preemptive SJF\n3. preemptive SJF\n4. non-preemptive priority\n5. preemptive priority\n6. Round Robin : \n");
	scanf("%d",Alg);
	printf("number of process : ");
	scanf("%d",numP);
	if(1){
		printf("time quantum : ");
		scanf("%d",tq);
	}
}

int main(){
	int IsRandom,Alg,numP=3,tq=0,i;
	srand(time(NULL));
	config(&IsRandom,&Alg,&numP,&tq);
	printf("**********************************************************************\n");
	printf("Random : %d ,Algorithm : %s , number of process : %d, time quantum : %d\n",IsRandom,algarr[Alg],numP,tq);
	printf("**********************************************************************\n");
	process** parray = (process**)malloc(sizeof(process*)*numP);
	printf("IF there are process that have same arrival time\nYou must type first coming process first\n");
	for(i=0;i<numP;i++){
		printf("*******insert value of %dth process******\n",i+1);
		parray[i]=make_process(IsRandom);
	}
	Result* result=NULL;
	printf("##############################################################\n");
	for(i=0;i<numP;i++){
		printf("%d process\nCpuBT : %d IOT : %d ArivalT : %d Priority : %d\n",i+1,parray[i]->cpuBT,parray[i]->IOBT,parray[i]->arrivalT,parray[i]->priority);
		int lc=parray[i]->CpuIO.LeftCpu,li=parray[i]->CpuIO.LeftIO,j=0;
		while(lc>0||li>0){
			if(j%2==0)printf("CPU:");
			else printf("IO:");
			printf("[%d] ",parray[i]->CpuIO.TurnArray[j]);
			if(j%2==0)lc-=parray[i]->CpuIO.TurnArray[j];
			else li-=parray[i]->CpuIO.TurnArray[j];
			j++;
		}
		printf("\n");
	}
	/*
	process** parray1 = (process**)malloc(sizeof(process*)*numP);
	process** parray2 = (process**)malloc(sizeof(process*)*numP);
	process** parray3 = (process**)malloc(sizeof(process*)*numP);
	process** parray4 = (process**)malloc(sizeof(process*)*numP);
	process** parray5 = (process**)malloc(sizeof(process*)*numP);
	copyProcess(parray,parray1,numP);
	copyProcess(parray,parray2,numP);
	copyProcess(parray,parray3,numP);
	copyProcess(parray,parray4,numP);
	copyProcess(parray,parray5,numP);*/
	printf("##############################################################\n");
	while(1){
//	printf("Choose Algorithm\n1. FCFS\n2. non-preemptive SJF\n3. preemptive SJF\n4. non-preemptive priority\n5. preemptive priority\n6. Round Robin : \n");
//	scanf("%d",&Alg);
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
	printf("##############################################################\n");
	break;
	}
	GanttChart(result);
	WTTT(result);
	CpuUtilization(result);
	return 0;
}

