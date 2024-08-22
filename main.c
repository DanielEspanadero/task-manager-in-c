#include "include/task.h"
#include "include/list.h"
#include "include/file.h"

#define DEFAULT_FILENAME "tasks.txt"

void displayMenu() {
    printf("\x1b[36mTask Manager\x1b[0m\n");
    printf("1. Add Task\n");
    printf("2. Display All Tasks\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Remove Task\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    Node *taskList = loadTasksFromFile(DEFAULT_FILENAME);
    int choice;
    char name[MAX_NAME_LEN];
    int priority;
    char deadline[MAX_DATE_LEN];
    char description[MAX_DESC_LEN];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter task priority (1-5): ");
                while (scanf("%d", &priority) != 1 || priority < 1 || priority > 5) {
                    printf("\x1b[31mInvalid priority. Enter a value between 1 and 5:\x1b[0m ");
                    while (getchar() != '\n');
                }
                getchar();

                printf("Enter task deadline (YYYY-MM-DD): ");
                fgets(deadline, sizeof(deadline), stdin);
                deadline[strcspn(deadline, "\n")] = 0;

                while (!isValidDate(deadline) || !isFutureDate(deadline)) {
                    printf("\x1b[31mInvalid date. Enter a valid future date (YYYY-MM-DD):\x1b[0m ");
                    fgets(deadline, sizeof(deadline), stdin);
                    deadline[strcspn(deadline, "\n")] = 0;
                }

                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0;

                taskList = addTask(taskList, createTask(name, priority, deadline, description));
                printf("\x1b[32mTask added successfully!\x1b[0m\n");
                break;

            case 2:
                printf("\x1b[33mDisplaying all tasks:\x1b[0m\n");
                displayTasks(taskList);
                break;

            case 3:
                printf("Enter the name of the task to mark as completed: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                Task *taskToComplete = findTask(taskList, name);
                if (taskToComplete) {
                    markTaskAsCompleted(taskToComplete);
                    printf("\x1b[32mTask '%s' marked as completed.\x1b[0m\n", name);
                } else {
                    printf("\x1b[31mTask '%s' not found.\x1b[0m\n", name);
                }
                break;

            case 4:
                printf("Enter the name of the task to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                taskList = removeTask(taskList, name);
                printf("\x1b[32mTask '%s' removed (if it existed).\x1b[0m\n", name);
                break;

            case 5:
                saveTasksToFile(DEFAULT_FILENAME, taskList);
                printf("\x1b[32mTasks saved successfully!\x1b[0m\n");
                printf("\x1b[32mExiting...\x1b[0m\n");
                return 0;

            default:
                printf("\x1b[31mInvalid option. Please try again.\x1b[0m\n");
                break;
        }
    }
}