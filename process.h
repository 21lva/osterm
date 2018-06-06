#ifndef PROCESS_H
#define PROCESS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "constants.h"

typedef struct _turn{
	//a sequence of a process showing what kind of operation is going to be done and how long.
	int NextType;//Cpu type operation : 0 , IO : 1
	int *TurnArray;//an array showing time amount of each operation
	int Index;//In array, what operation is next operation
	int LeftCpu;//total amount of left cpu type operation
	int LeftIO;//total amount of left IO type operation
	int X;
}turn;

typedef struct _process{
	int processID;//id of the process
	int cpuBT;//cpu burst time
	int IOBT;//I/O operation burst time
	int arrivalT;//arrival time
	int gettingT;//getting time: time when the process get in the ready queue. First it is same as arrival time
	int priority;
	int finishedT;
	turn CpuIO;
}process;

process* make_process(int Is_random);
void interrupt_process(process* target,int bywhom,int time);
void remove_process(process* target);
void process_free(process* target);
void _FinishProcess(process* target,int time);
int Is_finished_process(process* target);
//void copyProcess(process* parray1[],process* parray2[],int numP);

//#include "mainheader.h"

#endif
