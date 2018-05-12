#ifndef
#define ALG_H

#include "../structure/heap.h"
#include "../structure/process.h"
#include "../structure/stack.h"
#include "../structure/queue.h"
#include "../mainheader.h"


typedef struct _Running{
	process* Process;
	int timeQuantum;
}Running;

typedef struct _Result{
	stack* finished;
	queue* list;
	int totaltime;
	int idle;
}result;

Result* init_Result();
Running* init_Running(int timeq);
int RunningFinished(Running* running);
void ChangeRunning(Running* running,heap* ready);
int IsAvailProcess(heap* ready,int IsFCFS,int time);
int RunningInterrupted(Running* running,int bywhom);
void SpendTime(Running* running);
int AllFinished(Running* running,heap* heap1,heap* heap2);
void FinishProcess(Running* running,int time,stack* finished);
void FromstandbyToready(heap* standby,heap* ready,int time);
void freeall(Running* running, heap* heap1,heap* heap2);
void checkingList(Result* resutl,Running* running,int time);
#endif
