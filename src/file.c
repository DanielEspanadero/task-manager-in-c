#include "../include/file.h"

void saveTasksToFile(const char *filename, Node *taskList) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    Node *current = taskList;
    while (current != NULL) {
        Task *task = current->task;
        fprintf(file, "%s,%d,%s,%s,%d\n", task->name, task->priority, task->deadline, task->description, task->completed);
        current = current->next;
    }

    fclose(file);
}

Node* loadTasksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return NULL;
    }

    Node *taskList = NULL;
    Node *lastNode = NULL;
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

        Node *newNode = (Node*) malloc(sizeof(Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            free(task);
            fclose(file);
            return taskList;
        }
        newNode->task = task;
        newNode->next = NULL;

        if (taskList == NULL) {
            taskList = newNode;
        } else {
            lastNode->next = newNode;
        }
        lastNode = newNode;
    }

    fclose(file);
    return taskList;
}