#include "alg.h"


Result* init_Result(){
	Result* re = (Result*)malloc(sizeof(Result)*1);
	re->finished=init_stack();
	re->list=init_queue();
	re->totaltime=0;
	re->idle=0;
	return re;
}

Running* init_Running(int timeq){
	Running* re = (Running*)malloc(sizeof(Running)*1);
	re->Process=NULL;
	re->timeQuantum=timeq;
	return re;
}

int RunningFinished(Running* running){
	if(running->Process==NULL)return 0;
	if(running->Process->CpuIO.LeftCpu==0)return 1;
}

void ChangeRunning(Running* running,heap* ready){
	running->Process=heap_first(ready);
	heap_pop(ready);
}

int IsAvailProcess(heap* ready,int IsFCFS,int time){
	if(heap_first(ready)==NULL)return 0;
	if(IsFCFS && heap_first(ready)->gettingT > time)return 0;
	return 1;
}

int RunningInterrupted(Running* running,int bywhom){
	process* rp = running->Process;
	if(bywhom==0&&rp->CpuIO.TurnArray[rp->CpuIO.Index]==0)return 1;
	return 0;
}

void SpendTime(Running* running){
	if(running->Process==NULL)return;
	running->Process->CpuIO.LeftCpu--;
	running->Process->CpuIO.TurnArray[running->Process->CpuIO.Index]--;
}

int AllFinished(Running* running,heap* heap1,heap* heap2){
	if(!RunningFinished(running))return 0;
	if(heap_first(heap1)!=NULL||heap_first(heap2)!=NULL)return 0;
	return 1;
}

void FinishProcess(Running* running,int time,stack* finished){
	if(running->Process==NULL)return;
	running->Process->finishedT=time;
	if(running->Process->CpuIO.LeftIO!=0)running->Process->finishedT+=running->Process->CpuIO.LeftIO;
	stack_insert(finished,running->Process);
	running->Process=NULL;
}

void FromstandbyToready(heap* standby,heap* ready,int time){
	process* st,rd;
	while(1){
		st = heap_first(standby);
		if(st->gettingT>time)break;
		heap_insert(ready,st);
		heap_pop(standby);
	}
}
void Running_free(Running* target){
	process_free(target->Process);
	free(target);
}
void freeall(Running* running, heap* heap1,heap* heap2){
	Running_free(running);
	heap_free(heap1);
	heap_free(heap2);
}

void checkingList(Result* result,Running* running,int time){
	if(running->Process==NULL)int pid=-1;
	else int pid = running->Process->processID;
	queue_insert(result->list,pid,time,time+1);
}
