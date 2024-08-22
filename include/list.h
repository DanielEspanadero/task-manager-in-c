#ifndef LIST_H
#define LIST_H

#include "task.h"

Node* addTask(Node *list, Task *newTask);
void displayTasks(Node *list);
Node* removeTask(Node *list, char name[]);
Task* findTask(Node *list, char name[]);

#endif
