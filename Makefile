CC = gcc
CFLAGS = -Wall -I./include

all: task_manager

task_manager: main.o task.o list.o file.o
	$(CC) $(CFLAGS) -o task_manager main.o task.o list.o file.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

task.o: src/task.c include/task.h
	$(CC) $(CFLAGS) -c src/task.c

list.o: src/list.c include/list.h
	$(CC) $(CFLAGS) -c src/list.c

file.o: src/file.c include/file.h
	$(CC) $(CFLAGS) -c src/file.c

clean:
	rm -f *.o task_manager

