#include <stdio.h>
#include <time.h>
#include <stdlib.h>


srand(time(NULL));

process* make_process(int Is_random){
	static int pidDist=0;//process id will be distributed as auto increment
	process* newp = (process*)malloc(sizeof(process)*1);
	if(Is_random){
	newp->processID=++pidDist;
	newp->cpuBT = rrandom(CPUBT_RANGE);
	newp->IOBT = rrandom(IOBT_RANGE);
	newp->arrivalT = rrandom(ARRIVALT_RANGE);
	newp->priority = rrandom(PRIORITY_RANGE);
	
	make_queue(newp->turnqueue,newp->cpuBT,newp->IOBT,Is_random);
			}
	else{
		newp->processID=++pidDist;
		printf("insert cpu burst time : ");
		scanf("%d",&(newp->cpuBT));
		printf("insert I/O burst time : ");
		scanf("%d",&(newp->IOBT));
		printf("insert arrival time : ");
		scanf("%d",&(newp->arrivalT));
		printf("insert priority : ");
		scanf("%d",&(newp->priority));

		make_queue(newp->turnqueue,newp->cpuBT,newp->IOBT,Is_random);
	}
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
