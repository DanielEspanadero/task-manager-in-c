#include "../include/list.h"

Node* addTask(Node *list, Task *newTask) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        free(newTask);
        return list;
    }
    newNode->task = newTask;
    newNode->next = NULL;

    if (list == NULL) return newNode;

    Node *temp = list;
    while (temp != NULL) {
        if (strcmp(temp->task->name, newTask->name) == 0) {
            printf("\x1b[31mError: A task with the name '%s' already exists.\x1b[0m\n", newTask->name);
            free(newTask);
            free(newNode);
            return list;
        }
        temp = temp->next;
    }

    newNode->next = list;
    return newNode;
}

void displayTasks(Node *list) {
    Node *temp = list;
    while (temp != NULL) {
        printTask(temp->task);
        printf("-----------------------------\n");
        temp = temp->next;
    }
}

Node* removeTask(Node *list, char name[]) {
    Node *temp = list, *prev = NULL;

    while (temp != NULL && strcmp(temp->task->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return list;

    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = temp->next;
    }

    free(temp->task);
    free(temp);
    return list;
}

Task* findTask(Node *list, char name[]) {
    Node *temp = list;
    while (temp != NULL) {
        if (strcmp(temp->task->name, name) == 0) {
            return temp->task;
        }
        temp = temp->next;
    }
    return NULL;
}