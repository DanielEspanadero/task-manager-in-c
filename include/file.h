#ifndef FILE_H
#define FILE_H

#include "task.h"

void saveTasksToFile(const char *filename, Task *taskList);
Task* loadTasksFromFile(const char *filename);

#endif
