#include "algorithms.h"

//The algorithm return total running time 
Result* SJFA(process* parray[],int nump,int IsPreemptive){
	srand(time(NULL));
	heap* standby;//"standby" heap is sorted by using getting time
	heap* ready;//"ready" heap is sorted by using left cpu time
	Running* running=init_Running(0); 
	Result* result = init_Result();
	stack* finished = result->finished;
	int idle=-1;
	int time=0;

	//initialize heap
	//first, make heap with key value 1(getting time)
	//second, insert all processes in parray into heap
	ready=init_heap(3,nump);
	standby=init_heap(1,nump);
	for(time=0;time<nump;time++)heap_insert(standby,parray[time]);


	for(time=0;/*infinitely*/;time++){
		FromstandbyToready(standby,ready,time);

		if(running->Process==NULL){
			idle++;
			if(IsAvailProcess(ready,0,time)){
				ChangeRunning(running,ready);
			}
		}

		else if(RunningFinished(running)){
			FinishProcess(running,time,finished);
			if(IsAvailProcess(ready,0,time)){
				ChangeRunning(running,ready);
			}
		}

		else if(RunningInterrupted(running,BYIO)){
			interrupt_process(running->Process,BYIO,time);
			heap_insert(standby,running->Process);
			if(IsAvailProcess(ready,0,time)){
				ChangeRunning(running,ready);
			}
			else{
				running->Process=NULL;
			}
		}

		else if(IsPreemptive&&RunningPreemptive(running,ready,0)){
			interrupt_process(running->Process,BYPROCESS,time);
			heap_insert(standby,running->Process);
			if(IsAvailProcess(ready,0,time)){
				ChangeRunning(running,ready);
			}
		}
		if(AllFinished(running,standby,ready)){
			break;
		}
		checkingList(result,running,time);		
		SpendTime(running);
	}
	result->totaltime=time;
	result->idle=idle;
	return result;
}
