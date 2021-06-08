#include "Project.h"

void addTaskInProject(Project *project) {
    char temp = 0;
    Task *task = NULL;
    if (!project) return;

    printf("What type of task is it?\n"
           "1) Critical task\n"
           "2) Parallel task\n"
           "3) Exit\n");

    
    temp = getValidInt(1, 3);
    while (temp != 3) {
        task = getTask();
        if (temp) addTask(project->criticalTasks, task);
        else
            addTask(project->parallelTasks, task);

        temp = getValidInt(1, 3);
    }
}

Project *newProject() {
    Project *project = (Project*)malloc(sizeof(Project));

    if (!project) {
        printf("\nError in allocation memory in Project!!!\n");
        exit(-1);
    }

    project->projectName = getWord();

    project->peopleOnProject = getValidInt(0, INT_MAX);
    project->resourcesOnProject = getValidDouble(0, INT_MAX);

    addTaskInProject(project);

    return project;
}

int printProject(Project *project) {
    if (!project || ! !project->criticalTasks ||
        !project->parallelTasks) return 0;

    printf("\nProject name: \"%s\"", project->projectName);
    printf("\nPeople on project: %d", project->peopleOnProject);
    printf("\nResoursec: %lf", project->resourcesOnProject);
    
    printf("\nCritical path\n");
    printListOfTasks(project->criticalTasks);

    printf("\nParallel tasks\n");
    printListOfTasks(project->parallelTasks);

    printf("\nTotal srok\n");
    printDate(project->criticalTasks->head->startTaskTime);
    printDate(project->criticalTasks->tail->endTaskTime);

    return 1;
}

void deleteProject(Project *project) {
    deleteListOfTasks(project->criticalTasks);
    deleteListOfTasks(project->parallelTasks);
    free(project->projectName);
    free(project);
}
