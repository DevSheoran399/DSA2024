#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char userName[] = "Kunal";
char sapID[] = "500122002";
char batch[] = "46";

// Node structure to store a task
typedef struct Node {
    char task[100];
    char dueDate[11];
    int priority;
    struct Node* next;
} Node;

// Function prototypes
void addTask(Node** head);
void displayTasks(Node* head);
void deleteTask(Node** head);
void checkReminders(Node* head);
int isValidDate(const char* date);

int main() {
    Node* head = NULL;
    int choice;

    printf("\nWelcome, %s (SAP ID: %s, Batch: %s)\n", userName, sapID, batch);

    do {
        printf("To-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. Display Task\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(&head);
                checkReminders(head);
                break;
            case 2:
                displayTasks(head);
                checkReminders(head);
                break;
            case 3:
                deleteTask(&head);
                checkReminders(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new task to the linked list
void addTask(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory. Unable to add task.\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", newNode->task);

    printf("Enter due date (DD/MM/YYYY): ");
    scanf(" %10s", newNode->dueDate);
    if (!isValidDate(newNode->dueDate)) {
        printf("Invalid date format. Please use DD/MM/YYYY format\n");
        free(newNode);
        return;
    }

    printf("Enter priority (1 for low, 2 for medium, 3 for high): ");
    scanf("%d", &newNode->priority);

    newNode->next = *head;
    *head = newNode;

    printf("Task added successfully!\n");
}

// Function to display all tasks in the linked list
void displayTasks(Node* head) {
    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Tasks:\n");
    Node* current = head;
    int taskNumber = 1;

    while (current != NULL) {
        printf("%d. %s, Due Date: %s, Priority: %d\n", taskNumber, current->task, current->dueDate, current->priority);
        current = current->next;
        taskNumber++;
    }
}

// Function to delete a task from the linked list
void deleteTask(Node** head) {
    if (*head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    char taskToDelete[100];
    printf("Enter task description to delete: ");
    scanf(" %[^\n]", taskToDelete);

    Node* current = *head;
    Node* prev = NULL;

    // Traverse the linked list to find the task
    while (current != NULL) {
        if (strcmp(current->task, taskToDelete) == 0) {
            // Task found, delete it
            if (prev == NULL) {
                // Deleting the head node
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Task deleted successfully!\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Task not found.\n");
}

// Function to check for upcoming or overdue tasks
void checkReminders(Node* head) {
    time_t currentTime = time(NULL);
    struct tm* currentDate = localtime(&currentTime);
    int currentDay = currentDate->tm_mday;
    int currentMonth = currentDate->tm_mon + 1; 
    int currentYear = currentDate->tm_year + 1900; 

    Node* current = head;
    while (current != NULL) {
        int dueDay, dueMonth, dueYear;
        sscanf(current->dueDate, "%d/%d/%d", &dueDay, &dueMonth, &dueYear);

        if (currentYear > dueYear ||
            (currentYear == dueYear && currentMonth > dueMonth) ||
            (currentYear == dueYear && currentMonth == dueMonth && currentDay > dueDay)) {
            printf("Reminder: Task '%s' is overdue!\n", current->task);
        } else if (currentYear == dueYear && currentMonth == dueMonth && currentDay == dueDay) {
            printf("Reminder: Task '%s' is due today!\n", current->task);
        }

        current = current->next;
    }
}

// Function to validate date format (DD/MM/YYYY)
int isValidDate(const char* date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0; // Failed to parse all three components
    }

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) {
        return 0; // Invalid range for day, month, or year
    }

    return 1;
}
