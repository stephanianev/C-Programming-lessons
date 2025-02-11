#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 5
#define MAX_PROCESS_NAME 30

typedef struct {
    int id;
    char name[MAX_PROCESS_NAME + 1];
} Process;

extern Process processes[MAX_PROCESSES];
extern int processescount;

int createnewprocess(const char* name);
void stopprocess(int id);
void listprocesses(void);

#endif
