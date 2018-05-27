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
			printf("===%d time===\n",time);
			printf("1\n");
		FromstandbyToready(standby,ready,time);
			printf("2\n");

		if(running->Process==NULL){
			printf("3\n");
			idle++;
			if(IsAvailProcess(ready,0,time)){
			printf("4\n");
				ChangeRunning(running,ready);
			}
		}

		else if(RunningFinished(running)){
			printf("5\n");
			FinishProcess(running,time,finished);
			printf("6\n");
			if(IsAvailProcess(ready,0,time)){
			printf("7\n");
				ChangeRunning(running,ready);
			}
		}

		else if(RunningInterrupted(running,BYIO)){
			printf("8\n");
			interrupt_process(running->Process,BYIO,time);
			printf("9\n");
			heap_insert(standby,running->Process);
			printf("10\n");
			if(IsAvailProcess(ready,0,time)){
			printf("11\n");
				ChangeRunning(running,ready);
			printf("12\n");
			}
			else{
			printf("13\n");
				running->Process=NULL;
			}
		}

		else if(IsPreemptive&&RunningPreemptive(running,ready,0)){
			printf("14\n");
			interrupt_process(running->Process,BYPROCESS,time);
			printf("15\n");
			heap_insert(standby,running->Process);
			printf("16\n");
			if(IsAvailProcess(ready,0,time)){
			printf("17\n");
				ChangeRunning(running,ready);
			printf("18\n");
			}
		}
		if(AllFinished(running,standby,ready)){
			printf("19\n");
			//freeall(running,standby,ready);
			break;
		}
			printf("20\n");
		checkingList(result,running,time);		
		SpendTime(running);
	}
	result->totaltime=time;
	result->idle=idle;
	return result;
}
