#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"

typedef struct Task {
    Date *startTaskTime;
    Date *endTaskTime;

    char *taskName;

    struct Task *nextTask;
    struct Task *prevTask; 

}Task;

char* resizeLine(char *line);
char* getWord();
char* getWordFromFile(FILE *toRead);

Task *getTask();
void deleteTask(Task *task);
int printTask(Task *task);
void saveToFileTask(FILE *toWrite, Task *task);
Task* loadFromFileTask(FILE *toRead);
void saveToFileTask(FILE *toWrite, Task *task);
Task* loadFromFileTask(FILE *toRead);

#endif