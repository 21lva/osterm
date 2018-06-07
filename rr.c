#include "algorithms.h"

//The algorithm return total running time 
Result* RRA(process* parray[],int nump,int TimeQuantum){
	
	srand(time(NULL));
	heap* ready;//"ready" heap is sorted by using left cpu time
	process** standby = (process**)malloc(sizeof(process*)*(nump+1));
	int first=0,last=0;
	Running* running=init_Running(TimeQuantum); 
	Running* fake = init_Running(TimeQuantum);
	Result* result = init_Result();
	stack* finished = result->finished;
	int idle=-1;
	int time=0;

	//initialize heap
	//first, make heap with key value 1(getting time)
	//second, insert all processes in parray into heap
	ready=init_heap(1,nump);
	for(time=0;time<nump;time++)
	{
		if(parray[time]->arrivalT==0)standby[last++]=parray[time];
		else
			heap_insert(ready,parray[time]);
	}
	for(time=0;/*infinitely*/;time++){
		while(IsAvailProcess(ready,1,time)){
			ChangeRunning(fake,ready);
			standby[last]=fake->Process;
			last++;
			last%=nump+1;
		}
		if(running->Process==NULL){
			idle++;
			if(last!=first){
				running->Process=standby[first];
				first++;
				first%=nump+1;
				running->timeQuantum=TimeQuantum;
			}

		}

		else if(RunningFinished(running)){
			FinishProcess(running,time,finished);
			if(last!=first){
				running->Process=standby[first];
				first++;
				first%=nump+1;
				running->timeQuantum=TimeQuantum;
			}
				}

		else if(RunningInterrupted(running,BYIO)){
			interrupt_process(running->Process,BYIO,time);
			heap_insert(ready,running->Process);
			if(last!=first){
				running->Process=standby[first];
				first++;
				first%=nump+1;
				running->timeQuantum=TimeQuantum;
			}
			else{
				running->Process=NULL;
			}
		}
		else if(running->timeQuantum ==0){
			standby[last]=running->Process;
			interrupt_process(running->Process,BYTQ,time);
			last++;
			last%=nump+1;
			if(last!=first){
				running->Process=standby[first];
				first++;
				first%=nump+1;
				running->timeQuantum=TimeQuantum;
			}
			else{
				running->Process=NULL;
			}
		}
	 	if(AllFinished(running,ready,ready)){
			break;
		}
		checkingList(result,running,time);		
		SpendTime(running);
	}
	result->totaltime=time;
	result->idle=idle;
	return result;
}
