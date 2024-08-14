#include "../include/file.h"

void saveTasksToFile(const char *filename, Task *taskList) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    Task *current = taskList;
    while (current != NULL) {
        fprintf(file, "%s,%d,%s,%s,%d\n", current->name, current->priority, current->deadline, current->description, current->completed);
        current = current->next;
    }

    fclose(file);
}

Task* loadTasksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return NULL;
    }

    Task *taskList = NULL;
    Task *lastTask = NULL;
    char line[512];

    while (fgets(line, sizeof(line), file)) {
        Task *task = (Task*) malloc(sizeof(Task));
        if (!task) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return taskList;
        }

        sscanf(line, "%99[^,],%d,%19[^,],%255[^,],%d", task->name, &task->priority, task->deadline, task->description, &task->completed);
        task->completed = task->completed != 0;
        task->next = NULL;

        if (taskList == NULL) {
            taskList = task;
        } else {
            lastTask->next = task;
        }
        lastTask = task;
    }

    fclose(file);
    return taskList;
}

