#ifndef PROCESS_H
#define PROCESS_H

#include <time.h>


typedef struct _turn{
	//a sequence of a process showing what kind of operation is going to be done and how long.
	int NextType;//Cpu type operation : 0 , IO : 1
	int *TurnArray;//an array showing time amount of each operation
	int Index;//In array, what operation is next operation
	int LeftCpu;//total amount of left cpu type operation
	int LeftIO;//total amount of left IO type operation
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
void interrupt_process(process* target,int bywhom,int time,int startT);
void remove_process(process* target);
void process_free(process* target);
void FinishProcess(process* target,int time);
int Is_finished_process(process* target);

#endif
