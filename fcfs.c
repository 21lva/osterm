#include "algorithms.h"

//The algorithm return total running time 
Result* FCFSA(process* parray[],int nump){
	heap* ready;//"ready" heap is sorted by using getting time
	Running* running = init_Running(0); 
	Result* result = init_Result();
	stack* finished = result->finished;
	int idle=-1;
	int time=0;

	//printf("number of processes :  %d\n",nump);
	//initialize heap
	//first, make heap with key value 1(getting time)
	//second, insert all processes in parray into heap
	ready=init_heap(1,nump);
	for(time=0;time<nump;time++)heap_insert(ready,parray[time]);
	
	for(time=0;/*infinitely*/;time++){
		if(running->Process==NULL){
		//printf("time1 : %d\n",time);
			idle++;
			if(IsAvailProcess(ready,1,time))
			{
		//		printf("sdafsdffqfwefqwfqwf\n");
				ChangeRunning(running,ready);
			}
		}

		else if(RunningFinished(running)){
			int i=0;
//		printf("time2 : %d %d\n",heap_first(ready)->processID,ready->last);
			FinishProcess(running,time,finished);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready);
			}
		}

		else if(RunningInterrupted(running,BYIO)){
		//printf("time3 : %d\n",time);
			interrupt_process(running->Process,BYIO,time);
			heap_insert(ready,running->Process);
			if(IsAvailProcess(ready,1,time)){
				ChangeRunning(running,ready);
			}
		}
	
		if(AllFinished(running,ready,ready)){
	//	printf("time4 : %d\n",time);
//			freeall(running,ready,ready);
		break;
		}
		checkingList(result,running,time);
		SpendTime(running);
	}
	result->totaltime=time;
	result->idle=idle;
	printf("finished algorithm!!!\n");
	return result;
}
