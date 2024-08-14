#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define MAX_DESC_LEN 255
#define MAX_DATE_LEN 20

typedef struct Task {
    char name[MAX_NAME_LEN];
    int priority;
    char deadline[MAX_DATE_LEN];
    char description[MAX_DESC_LEN];
    int completed;
    struct Task *next;
} Task;

Task* createTask(char name[], int priority, char deadline[], char description[]);
void printTask(Task *task);
void markTaskAsCompleted(Task *task);
int isValidDate(char *date);
int isFutureDate(char *date);

#endif
