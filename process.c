#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define USECPU 1
#define USEIO 0
#define CPUBT_RANGE 10
#define IOBT_RANGE 10
#define ARRIVALT_RANGE 10
#define PRIORITY_RANGE 10
#define rrandom(X) ((rand()%(X))+1)//return random number from 1 to X

srand(time(NULL));

typedef struct _process{
	int processID;
	int cpuBT;//cpu burst time
	int IOBT;//I/O burst time
	int arrivalT;//arrival time;
	int priority;//priority
}process;

process* make_process(){
	static int pidDist=0;//process id will be distributed as auto increment
	process* newp = (process*)malloc(sizeof(process)*1);
	
	newp.processID=++pidDist;
	newp.cpuBT = rrandom(CPUBT_RANGE);
	newp.IOBT = rrandom(IOBT_RANGE);
	newp.arrivalT = rrandom(ARRIVALT_RANGE);
	newp.priority = rrandom(PRIORITY_RANGE);
	
	return newp;
}

process* interrupt_process(process* target,int type,int amount){
	if(type==USECPU){
	//using cpu
		//after cpu operation,if there is interruption, arrival time should be increased because the process should get the ready queue.
		target->cpuBT-=amount;
		target->arrivalT+=amount;
	}
	else{
		//after IO operation, arrival time should be increased because the process should get the ready queue.
		target->IOBT-=amount;
		target->arrival+=amount;
	}
}

void remove_process(process* target){
	free(target);	
}

int Is_finished_process(process* target){
	//after interrupt, we must check this process is finished or not
	if(target->cpuBT<=0){
	//if there is nothing to do on cpu, then we must remove it, even if there is extra time to do in I/O operation. Because the only left I/O operation does not affect to turnaround time and waiting time.
		remove_process(target);
		return 1;
	}
	return 0;
}
