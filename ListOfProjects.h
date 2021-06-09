#ifndef LISTOFPROJECTS_H
#define LISTOFPROJECTS_H
#include "Project.h"

typedef struct ListOfProjects {
    Project *head;
    Project *tail;

    unsigned int length;
}ListOfProjects;

ListOfProjects* newListOfProjects();
void printProjectShort(ListOfProjects *list);
void addProjectEnd(ListOfProjects *list, Project *newProject);
void addProjectFront(ListOfProjects *list, Project *newProject);
Project *deleteProjectInList(ListOfProjects *list, const char *nameToSearch);
void deleteListOfProjects(ListOfProjects *list);
void saveToFileListOfProjects(FILE *toWrite, ListOfProjects *list);
ListOfProjects* loadFromFileListOfProjects(FILE *toRead);

#endif