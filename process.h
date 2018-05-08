#ifndef PROCESS_H
#define PROCESS_H

#define USECPU 1
#define USEIO 0
#define CPUBT_RANGE 10
#define IOBT_RANGE 10
#define ARRIVALT_RANGE 10
#define PRIORITY_RANGE 10
#define rrandom(X) ((rand()%(X))+1)//return random number from 1 to X

#include "queue.h"
typedef _process{
	int processID;//id of the process
	int cpuBT;//cpu burst time
	int IOBT;//I/O operation burst time
	int arrivalT;//arrival time
	int priority;
	queue* turnqueue;//queue consisting of what operation has to be done after a process
}process;

process* make_process(int Is_random);
process* interrupt_process(process* target,int type,int amount);
void remove_process(process* target);
int Is_finished_process(process* target);

#endif
