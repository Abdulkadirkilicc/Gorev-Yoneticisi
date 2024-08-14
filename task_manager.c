#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_DESC 100
#define TASK_FILE "tasks.txt"

typedef struct Task {
    char description[MAX_TASK_DESC];
    int isCompleted;
    struct Task *next;
} Task;

Task* createTask(char *description, int isCompleted) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    if (newTask != NULL) {
        strncpy(newTask->description, description, MAX_TASK_DESC - 1);
        newTask->description[MAX_TASK_DESC - 1] = '\0'; 
        newTask->isCompleted = isCompleted;
        newTask->next = NULL;
    }
    return newTask;
}

void addTask(Task **head, char *description) {
    Task *newTask = createTask(description, 0);
    if (newTask == NULL) {
        printf("Gorev olusturulamadý.\n");
        return;
    }

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
    saveTasksToFile(*head);
    printf("Gorev eklendi: %s\n", description);
    printf("-----------------------------\n");
}

void listTasks(Task *head) {
    Task *temp = head;
    int taskNumber = 1;
    if (temp == NULL) {
        printf("Henuz bir gorev eklenmedi.\n");
        printf("-----------------------------\n");
        return;
    }
    
    printf("Gorevler:\n");
    while (temp != NULL) {
        printf("%d. [%s] %s\n", taskNumber, temp->isCompleted ? "Tamamlandi" : "Bekliyor", temp->description);
        temp = temp->next;
        taskNumber++;
    }
    printf("-----------------------------\n");
}

void completeTask(Task *head, int taskNumber) {
    Task *temp = head;
    int currentNumber = 1;
    while (temp != NULL) {
        if (currentNumber == taskNumber) {
            temp->isCompleted = 1;
            saveTasksToFile(head);
            printf("Gorev tamamlandi: %s\n", temp->description);
            printf("-----------------------------\n");
            return;
        }
        temp = temp->next;
        currentNumber++;
    }
    printf("Gecersiz gorev numarasi.\n");
    printf("-----------------------------\n");
}

void deleteCompletedTasks(Task **head) {
    Task *current = *head;
    Task *prev = NULL;

    while (current != NULL) {
        if (current->isCompleted) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Task *temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    saveTasksToFile(*head);
    printf("Tamamlanmis gorevler silindi.\n");
    printf("-----------------------------\n");
}

void saveTasksToFile(Task *head) {
    FILE *file = fopen(TASK_FILE, "w");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    Task *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s;%d\n", temp->description, temp->isCompleted);
        temp = temp->next;
    }

    fclose(file);
    printf("Gorevler dosyaya kaydedildi.\n");
    printf("-----------------------------\n");
}

void loadTasksFromFile(Task **head) {
    FILE *file = fopen(TASK_FILE, "r");
    if (file == NULL) {
        printf("Gorev dosyasi bulunamadi, yeni bir dosya olusturulacak.\n");
        printf("-----------------------------\n");
        return;
    }

    char line[MAX_TASK_DESC + 10]; 
    while (fgets(line, sizeof(line), file)) {
        char description[MAX_TASK_DESC];
        int isCompleted;

        sscanf(line, "%[^;];%d", description, &isCompleted);
        addTask(head, description);

        Task *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (isCompleted) {
            temp->isCompleted = 1;
        }
    }

    fclose(file);
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main() {
    Task *taskList = NULL;
    loadTasksFromFile(&taskList);

    int choice;
    char description[MAX_TASK_DESC];
    int taskNumber;

    do {
        clearScreen(); 

        printf("-----------------------------------\n");
        printf("Gorev Yonetici\n");
        printf("1. Gorev Ekle\n");
        printf("2. Gorevleri Listele\n");
        printf("3. Gorevi Tamamla\n");
        printf("4. Tamamlanmis Gorevleri Sil\n");
        printf("5. Cikis\n");
        printf("-----------------------------------\n");
        printf("Seciminiz: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0; 
        }

        switch (choice) {
            case 1:
                while (getchar() != '\n'); 
                printf("Gorev aciklamasi: ");
                fgets(description, MAX_TASK_DESC, stdin);
                description[strcspn(description, "\n")] = 0; 
                addTask(&taskList, description);
                break;
            case 2:
                listTasks(taskList);
                printf("Devam etmek icin herhangi bir tusa basiniz...");
                while (getchar() != '\n'); 
                getchar(); 
                break;
            case 3:
                listTasks(taskList); 
                printf("Tamamlanacak gorev numarasi: ");
                if (scanf("%d", &taskNumber) != 1) {
                    while (getchar() != '\n'); 
                    taskNumber = 0; 
                }
                completeTask(taskList, taskNumber);
                printf("Devam etmek icin herhangi bir tusa basiniz...");
                while (getchar() != '\n');
                getchar(); 
                break;
            case 4:
                deleteCompletedTasks(&taskList);
                printf("Devam etmek icin herhangi bir tusa basiniz...");
                while (getchar() != '\n'); 
                getchar(); 
                break;
            case 5:
                printf("Cikis yapiliyor...\n");
                saveTasksToFile(taskList);
                break;
            default:
                printf("Gecersiz secim, tekrar deneyin.\n");
                printf("-----------------------------\n");
        }
    } while (choice != 5);

    Task *temp;
    while (taskList != NULL) {
        temp = taskList;
        taskList = taskList->next;
        free(temp);
    }

    return 0;
}

