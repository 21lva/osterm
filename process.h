#ifndef PROCESS_H
#define PROCESS_H

#include "queue.h"
typedef _process{
	int pid;
	int cpuBT;
	int IOBT;
	int arrivalT;
	int priority;
	queue* turnqueue;
}process;

process* make_process();
process* interrupt_process(process* target,int type,int amount);
void remove_process(process* target);
int Is_finished_process(process* target);

#endif
