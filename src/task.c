#include "../include/task.h"

int isValidDate(char *date) {
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;

    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) return 0;
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) return 0;

    return 1;
}

int isFutureDate(char *date) {
    struct tm taskTime = {0};
    sscanf(date, "%d-%d-%d", &taskTime.tm_year, &taskTime.tm_mon, &taskTime.tm_mday);
    taskTime.tm_year -= 1900;
    taskTime.tm_mon -= 1;

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    time_t taskTimestamp = mktime(&taskTime);
    time_t currentTimestamp = mktime(currentTime);

    return difftime(taskTimestamp, currentTimestamp) >= 0;
}

Task* createTask(char name[], int priority, char deadline[], char description[]) {
    Task *newTask = (Task*) malloc(sizeof(Task));
    if (!newTask) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newTask->name, name);
    newTask->priority = priority;
    strcpy(newTask->deadline, deadline);
    strcpy(newTask->description, description);
    newTask->completed = 0;
    return newTask;
}

void printTask(Task *task) {
    if (task == NULL) return;

    const char* color = task->completed ? "\x1b[32m" : "\x1b[31m";
    printf("%sName: %s\n", color, task->name);
    printf("Priority: %d\n", task->priority);
    printf("Deadline: %s\n", task->deadline);
    printf("Description: %s\n", task->description);
    printf("Completed: %s\x1b[0m\n", task->completed ? "Yes" : "No");
}

void markTaskAsCompleted(Task *task) {
    if (task != NULL) {
        task->completed = 1;
    }
}
