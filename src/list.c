#include "../include/list.h"

Task* addTask(Task *list, Task *newTask) {
    if (list == NULL) return newTask;
    
    Task *temp = list;
    while (temp != NULL) {
        if (strcmp(temp->name, newTask->name) == 0) {
            printf("\x1b[31mError: A task with the name '%s' already exists.\x1b[0m\n", newTask->name);
            free(newTask);
            return list;
        }
        temp = temp->next;
    }
    
    newTask->next = list;
    return newTask;
}

void displayTasks(Task *list) {
    Task *temp = list;
    while (temp != NULL) {
        printTask(temp);
        printf("-----------------------------\n");
        temp = temp->next;
    }
}

Task* removeTask(Task *list, char name[]) {
    Task *temp = list, *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return list;

    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return list;
}

Task* findTask(Task *list, char name[]) {
    Task *temp = list;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

