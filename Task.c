#include "Task.h"

char* resizeLine(char *line) {
    char *tempLine = NULL;
    unsigned int length = strlen(line);

    tempLine = (char*)realloc(line, (length + 1) * sizeof(char));
    if (!tempLine) return line;

    tempLine[length] = '\0';

    return tempLine;
}

char* getWord() {
    char *tempLine = (char*)malloc(256 * sizeof(char));
    if (!tempLine) return NULL;

    scanf("%[^\n]255s", tempLine);
    scanf("%*c");
    tempLine = resizeLine(tempLine);
    return tempLine;
}

Task *getTask() {
    Task *task = (Task*)malloc(sizeof(Task));
    if (!task) {
        printf("\nError in memory allocation in \"Task\"\n");
        exit(1);
    }

    printf("\nEnter task name: ");
    task->taskName = getWord();

    printf("\nEnter starting time: ");
    task->startTaskTime = getDate();

    printf("\nEnter ending time: ");
    task->endTaskTime = getDate();

    while (compareDate(task->endTaskTime, task->startTaskTime) != 1) {
        printf("\nWrong input. End date must be later then start date.\n"
               "Enter ending time again");
        rewriteDate(task->endTaskTime);
    }

    task->nextTask = task->prevTask = NULL;

    return task;
}

void deleteTask(Task *task) {
    if (!task) return;

    free(task->taskName);
    deleteDate(task->startTaskTime);
    deleteDate(task->endTaskTime);
    free(task);
}

int printTask(Task *task) {
    if (!task) return 0;

    printf("\nTask name: %s", task->taskName);

    printf("\nStarting time: ");
    printDate(task->startTaskTime);

    printf("\nEnding time: ");
    printDate(task->endTaskTime);

    return 1;
}

void saveToFileTask(FILE *toWrite, Task *task) {
    if (!toWrite || !task) return;

    fprintf(toWrite, "%s\n", "Task name");
    fprintf(toWrite, "%s\n", task->taskName);
    fprintf(toWrite, "%s\n", "Starting date");
    saveToFileDate(toWrite, task->startTaskTime);
    fprintf(toWrite, "%s\n", "Ending date");
    saveToFileDate(toWrite, task->endTaskTime);
}