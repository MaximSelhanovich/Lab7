#ifndef PROJECT_H
#define PROJECT_H
#include "ListOfTasks.h"

typedef struct Project {
    ListOfTasks *criticalTasks;
    ListOfTasks *parallelTasks;
    char *projectName;
    int peopleOnProject;
    double resourcesOnProject;

    struct Project *nextProject;
    struct Project *prevProject;
}Project;

void addTaskInProject(Project *project);
Project *newProject();
int printDeadlines(Project *project);
int printProject(Project *project);
void deleteProject(Project *project);
void saveToFileProject(FILE *toWrite, Project *project);
Project* loadFromFileProject(FILE *toRead);
Task *deleteTaskInProject(Project *project, char *nameToSearch);

#endif