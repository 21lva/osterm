#include "process.h"
#include <time.h>
//srand(time(NULL));

void randomize(){
	srand(time(NULL));
	int i=0;
	for(i=0;i<(rand()%RAND_MAX);i++)(rand()%RAND_MAX);
}

void make_turn(process* pp,int Is_random,int cputime,int iotime){
	randomize();
	//printf("%d %d",cputime,iotime);	
	int tmpcpu=cputime,tmpio=iotime;//variables used to check how much time we used for each operation
	pp->CpuIO.TurnArray=(int*)malloc(sizeof(int)*(cputime+iotime));
	int *target=pp->CpuIO.TurnArray;
	if(Is_random){
		//if the turn should be decided randomly
		//the first operation must cpu operation
		//although it is just 1 time unit
		target[0]=rrandom(tmpcpu);
		tmpcpu-=target[0];
		int next=1,index=1;
	//printf("fasdfafasfaf\n");
		while(tmpcpu>0 && tmpio>0){
			if(next==0){
				target[index]=rrandom(tmpcpu);
				tmpcpu-=target[index++];
				next=1;
			}
			else{
				target[index]=rrandom(tmpio);
				tmpio-=target[index++];
				next=0;
			}
			//printf("%d %d\n",tmpcpu,tmpio);
		}
		if(tmpcpu>0)target[index++]=tmpcpu;
		if(tmpio>0)target[index++]=tmpio;
	}
	else{
		int index=0,next=0;
		while(tmpcpu>0&&tmpio>0){
			if(next==0){
				printf("CPU type %dth operation, insert how much?? from 1 to %d : ",index+1,tmpcpu);
				scanf("%d",&target[index]);
				if(target[index]<=0||target[index]>tmpcpu){
					printf("the value must be more than zero and smaller than or equal to %d",tmpcpu);
					continue;
				}
				tmpcpu-=target[index++];
				next=1;
			}
			else{
				printf("IO type %dth operation, insert how much?? from 1 to %d : ",index+1,tmpio);
				scanf("%d",&target[index]);
				if(target[index]<=0||target[index]>tmpio){
					printf("the value must be more than zero and smaller than or equal to %d",tmpio);
					continue;
				}
				tmpio-=target[index++];
				next=0;
			}
		}
		if(tmpcpu>0)target[index++]=tmpcpu;
		if(tmpio>0)target[index++]=tmpio;
	}
}

process* make_process(int Is_random){
	//printf("\nmaking process\n");
	randomize();
	static int pidDist=0;//process id will be distributed as auto increment
	process* newp = (process*)malloc(sizeof(process)*1);
	if(Is_random){
	newp->processID=++pidDist;
	newp->cpuBT = rrandom(CPUBT_RANGE);
	newp->IOBT = rrandom(IOBT_RANGE);
	newp->arrivalT = rrandom(ARRIVALT_RANGE);
	newp->priority = rrandom(PRIORITY_RANGE);

	newp->gettingT = newp->arrivalT;
	newp->finishedT=-1;
	newp->CpuIO.NextType=0;
	newp->CpuIO.Index=0;
	newp->CpuIO.LeftCpu=newp->cpuBT;
	newp->CpuIO.LeftIO=newp->IOBT;
	printf("id : %d cpubt : %d iobt : %d arri : %d  prio :%d\n",newp->processID,newp->cpuBT,newp->IOBT,newp->arrivalT,newp->priority);
	make_turn(newp,Is_random,newp->cpuBT,newp->IOBT);
	}
	else{
		newp->processID=++pidDist;
		printf("insert cpu burst time : ");
		scanf("%d",&(newp->cpuBT));
		printf("insert I/O burst time : ");
		scanf("%d",&(newp->IOBT));
		printf("insert arrival time : ");
		scanf("%d",&(newp->arrivalT));
		printf("insert priority : ");
		scanf("%d",&(newp->priority));
		newp->finishedT=-1;
		newp->gettingT = newp->arrivalT;
		newp->CpuIO.NextType=0;
		newp->CpuIO.Index=0;
		newp->CpuIO.LeftCpu=newp->cpuBT;
		newp->CpuIO.LeftIO=newp->IOBT;
		make_turn(newp,Is_random,newp->cpuBT,newp->IOBT);
	}
	return newp;
}

void interrupt_process(process* target,int bywhom,int time){
	if(bywhom==BYPROCESS||bywhom==BYTQ){
	//in case of interrupted by a process or time slice expired
		target->gettingT = time;
	}
	else{
	//If the interruption is due to an I/O operation
		target->gettingT = time + target->CpuIO.TurnArray[target->CpuIO.Index+1];
		target->CpuIO.LeftIO -= target->CpuIO.TurnArray[target->CpuIO.Index+1];
		target->CpuIO.Index+=2;
	}
}

void remove_process(process* target){
	free(target);	
}

void turn_free(turn* target){
	free(target->TurnArray);
	free(target);
}
void process_free(process* target){
	turn_free(&(target->CpuIO));
	free(target);
}

void _FinishProcess(process* target, int time){
	target->finishedT=time;
	if(target->CpuIO.LeftIO!=0)target->finishedT+=target->CpuIO.LeftIO;
	
}
int Is_finished_process(process* target){
	if(target->CpuIO.LeftCpu<=0){
		return 1;
	}
	return 0;
}
