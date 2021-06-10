#ifndef LISTOFTASKS_H
#define LISTOFTASKS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"

typedef struct ListOfTasks {
    Task *head;
    Task *tail;

    unsigned int length;

}ListOfTasks;

ListOfTasks* newListOfTasks();
void addTaskEnd(ListOfTasks *list, Task *newTask);
void addTaskFront(ListOfTasks *list, Task *newTask);
void addTask(ListOfTasks *list, Task *newTask);
void removeTaskEnd(ListOfTasks *list);
void removeTaskFront(ListOfTasks *list);
int searchTask(ListOfTasks *list, const char *nameToSearch);
Task *deleteTaskInList(ListOfTasks *list, const char *nameToSearch);
void deleteListOfTasks(ListOfTasks *list);
int printListOfTasks(ListOfTasks *list);
void saveToFileListOfTasks(FILE *toWrite, ListOfTasks *list);
ListOfTasks* loadFromFileListOfTasks(FILE *toRead);

#endif