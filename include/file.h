#ifndef FILE_H
#define FILE_H

#include "task.h"

void saveTasksToFile(const char *filename, Node *taskList);
Node* loadTasksFromFile(const char *filename);
#endif
