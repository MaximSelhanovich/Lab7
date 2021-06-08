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
}Project;

void addTaskInProject(Project *project);
Project *newProject();
int printProject(Project *project);
void deleteProject(Project *project);

#endif