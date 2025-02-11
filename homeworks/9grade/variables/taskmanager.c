#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processes.h"

#ifdef _WIN32
#define CLEAR_SCREEN() printf("\033[H\033[J")
#else
#define CLEAR_SCREEN() system("clear")
#endif

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void display_menu() {
    printf("\nTask Manager\n");
    printf("1. Create New Process\n");
    printf("2. List All Processes\n");
    printf("3. Stop a Process\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char process_name[MAX_PROCESS_NAME + 1];
    int process_id;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CLEAR_SCREEN();
                printf("Enter process name: ");
                scanf("%s", process_name);

                process_id = createnewprocess(process_name);
                if (process_id == 0) {
                    CLEAR_SCREEN();
                    printf(RED "Error: Maximum number of processes reached. Stop a process to create a new one.\n" RESET);
                } else {
                    CLEAR_SCREEN();
                    printf("Process created with ID: %d\n", process_id);
                }
                break;

            case 2:
                CLEAR_SCREEN();
                printf("Listing all processes:\n");
                listprocesses();
                break;

            case 3:
                CLEAR_SCREEN();
                printf("Enter process ID to stop: ");
                scanf("%d", &process_id);

                stopprocess(process_id);
                CLEAR_SCREEN();
                printf("Process stopped (if it existed).\n");
                break;

            case 4:
                CLEAR_SCREEN();
                printf(RED "Exiting Task Manager.\n" RESET);
                return 0;

            default:
                CLEAR_SCREEN();
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    }

    return 0;
}