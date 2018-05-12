CC=gcc

op : main.o process.o heap.o queue.o stack.o alg.o fcfs.o rr.o sjf.o priority.o evaluation.o
	gcc -o op main.o process.o heap.o queue.o stack.o alg.o fcfs.o rr.o sjf.o priority.o evaluation.o

process.o : process.c
	gcc -c process.c

heap.o : heap.c
	gcc -c heap.c

queue.o : queue.c
	gcc -c queue.c

stack.o : stack.c
	gcc -c stack.c

alg.o : alg.c
	gcc -c alg.c
fcfs.o : fcfs.c
	gcc -c algorithms.h fcfs.c
rr.o : rr.c
	gcc -c rr.c
sjf.o : sjf.c
	gcc -c sjf.c
priority.o : priority.c
	gcc -c priority.c

evaluation.o : evaluation.c
	gcc -c evaluation.c

clean:
	rm -r *.o
