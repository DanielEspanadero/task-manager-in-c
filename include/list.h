#ifndef LIST_H
#define LIST_H

#include "task.h"

Task* addTask(Task *list, Task *newTask);
void displayTasks(Task *list);
Task* removeTask(Task *list, char name[]);
Task* findTask(Task *list, char name[]);

#endif
