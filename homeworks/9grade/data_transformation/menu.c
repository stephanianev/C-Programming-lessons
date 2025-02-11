#include <stdio.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#ifdef _WIN32
#define CLEAR_SCREEN() printf("\033[H\033[J")
#else
#define CLEAR_SCREEN() system("clear")
#endif

void switch_light(unsigned char *state, int room) {
    if (room < 1 || room > 8) {
        printf(RED "Invalid room number. Please enter a number between 1 and 8.\n" RESET);
        return;
    }
    *state ^= (1 << (room - 1));
}

void print_state(unsigned char state) {
    CLEAR_SCREEN();
    printf(YEL "The light is on in rooms: " RESET);
    int found = 0;
    for (int i = 0; i < 8; i++) {
        if (state & (1 << i)) { 
            printf("%d ", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf(RED "None" RESET);
    }
    printf("\n");
}

int main() {
    unsigned char state = 0;
    int choice, room;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CLEAR_SCREEN();
                printf("Enter room number (1-8): ");
                scanf("%d", &room);
                switch_light(&state, room);
                break;
            case 2:
                CLEAR_SCREEN();
                print_state(state);
                break;
            case 3:
                CLEAR_SCREEN();
                printf("Exiting...\n");
                return 0;
            default:
                CLEAR_SCREEN();
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    }

    return 0;
}