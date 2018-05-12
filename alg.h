#ifndef ALG_H
#define ALG_H

#include "heap.h"
#include "process.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _Running{
	process* Process;
	int timeQuantum;
}Running;

typedef struct _Result{
	stack* finished;
	queue* list;
	int totaltime;
	int idle;
}Result;

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
