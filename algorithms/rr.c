#include "alg.h"

//The algorithm return total running time 
Result* RR(process* parray[],int nump,int TimeQuantum){
	//heap* standby;//"standby" heap is sorted by using getting time
	heap* ready;//"ready" heap is sorted by using left cpu time
	Running* running=init_Running(TimeQuantum); 
	Result* result = init_Result();
	stack* finished = result->finished;
	int idle=-1;
	int time=0;

	//initialize heap
	//first, make heap with key value 1(getting time)
	//second, insert all processes in parray into heap
	ready=init_heap(1,nump);
	//standby=init_heap(1,nump);
	for(time=0;time<nump;time++)heap_insert(ready,parray[time]);


	for(time=0;/*infinitely*/;time++){
		//FromstandbyToready(standby,ready,time);

		if(running->Process==NULL){
			idle++;
			if(IsAvailProcess(ready,1,time))
				ChangeRunning(running,ready);
		}

		else if(RunningFinished(running)){
			FinishProcess(running,time,finihsed);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready);
			}
		}

		else if(RunningInterrupted(BYIO)){
			interrupt_process(running->Process,BYIO,time);
			heap_insert(standby,running->Process);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready);
			}
		}
		else if(running->timeQuantum ==0){
			interrupt_process(running->Process,BYTQ,time);
			heap_insert(standby,running->Process);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready);
			}
		}
		else if(IsPreemptive&&RunningInterrupted(BYPROCESS)){
			interrupt_process(running->Process,BYPROCESS,time);
			heap_insert(standby,running->Process);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready,time);
			}
		}
		else if(AllFinished(running,ready,ready)){
			freeall(running,ready,ready);
			break;
		}
		checkingList(result,running,time);		
		SpendTime(running);
	}
	result->time=time;
	result->idle=idle;
	return result;
}
