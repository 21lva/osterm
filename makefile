CC=gcc

op : main.o ./algorithms/*.o ./structure/*.o ./evaluation/*.o
	gcc -o op main.o ./algorithms/*.o ./structure/*.o ./evaluation/*.o


