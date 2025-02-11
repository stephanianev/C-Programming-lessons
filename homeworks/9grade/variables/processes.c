#include <stdio.h>
#include <string.h>
#include "processes.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

Process processes[MAX_PROCESSES];
int processescount = 0;
static int lastprocessid = 1;

static int nextprocessid() {
    if (lastprocessid < 1) {
        return 0;
    }
    return lastprocessid++;
}


int createnewprocess(const char* name) {
    if (processescount >= MAX_PROCESSES) {
        return 0;
    }

    int id = nextprocessid();
    if (id == 0) {
        return 0;
    }

    Process new_process = { .id = id };
    strncpy(new_process.name, name, MAX_PROCESS_NAME);
    new_process.name[MAX_PROCESS_NAME] = '\0';

    processes[processescount++] = new_process;
    return id;
}

void stopprocess(int id) {
    int found = -1;

    for (int i = 0; i < processescount; ++i) {
        if (processes[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf(RED "Process not found!" RESET);
        return;
    }

    for (int i = found; i < processescount - 1; ++i) {
        processes[i] = processes[i + 1];
    }

    processescount--;
}

void listprocesses() {
    for (int i = 0; i < processescount; ++i) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}