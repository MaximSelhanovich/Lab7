#ifndef LISTOFPROJECTS_H
#define LISTOFPROJECTS_H
#include "Project.h"

typedef struct ListOfProjects {
    Project *head;
    Project *tail;

    unsigned int length;
}ListOfProjects;

void printProjectNames(ListOfProjects *list);
Project *deleteProjectInList(ListOfProjects *list, const char *nameToSearch);
void deleteListOfProjects(ListOfProjects *list);
void saveToFileListOfProjects(FILE *toWrite, ListOfProjects *list);

#endif