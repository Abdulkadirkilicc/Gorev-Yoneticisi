#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define MAX_TASK_DESC 100

// Görev yapısı
typedef struct Task {
    char description[MAX_TASK_DESC];
    int isCompleted;
    struct Task *next;
} Task;

// Fonksiyon Prototipleri
Task* createTask(char *description);
void addTask(Task **head, char *description);
void listTasks(Task *head);
void completeTask(Task *head, int taskNumber);
void deleteCompletedTasks(Task **head);
void saveTasksToFile(Task *head, const char *filename);
void loadTasksFromFile(Task **head, const char *filename);

#endif // TASK_MANAGER_H
