#include "Project.h"

Project *newProject() {
    Project *project = (Project*)malloc(sizeof(Project));

    if (!project) {
        printf("\nError in allocation memory in Project!!!\n");
        exit(-1);
    }

    printf("Enter project name\n");
    project->projectName = getWord();

    printf("Enter people on project\n");
    project->peopleOnProject = getValidInt(0, INT_MAX);

    printf("Enter resources on project\n");
    project->resourcesOnProject = getValidDouble(0, INT_MAX);

    project->criticalTasks = project->parallelTasks = NULL;

    return project;
}

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

int printDeadlines(Project *project) {
    if (!project || !project->criticalTasks || !project->parallelTasks ||
        !project->criticalTasks->head || !project->parallelTasks->head) {
            printf("\nThere are no tasks\n");
            return 0;
        }

    printDate(project->criticalTasks->head->startTaskTime);
    printDate(project->criticalTasks->tail->endTaskTime);

    return 1;
}

int printProject(Project *project) {
    if (!project || !project->criticalTasks ||
        !project->parallelTasks) return 0;

    printf("\nProject name: \"%s\"", project->projectName);
    printf("\nPeople on project: %d", project->peopleOnProject);
    printf("\nResoursec: %f", project->resourcesOnProject);

    printf("\nCritical tasks\n");
    printListOfTasks(project->criticalTasks);

    printf("\nParallel tasks\n");
    printListOfTasks(project->parallelTasks);

    printf("\nDeadlines\n");
    printDeadlines(project);

    return 1;
}

void deleteProject(Project *project) {
    if (!project) return;

    deleteListOfTasks(project->criticalTasks);
    deleteListOfTasks(project->parallelTasks);
    free(project->projectName);
    free(project);
}

void saveToFileProject(FILE *toWrite, Project *project) {
    if (!toWrite || !project) return;

    fprintf(toWrite, "%s\n", "Project name");
    fprintf(toWrite, "%s\n", project->projectName);
    fprintf(toWrite, "%d ", project->peopleOnProject);
    fprintf(toWrite, "%f\n", project->resourcesOnProject);

    fprintf(toWrite, "%s\n", "Critical tasks");
    saveToFileListOfTasks(toWrite, project->criticalTasks);

    fprintf(toWrite, "%s\n", "Parallel tasks");
    saveToFileListOfTasks(toWrite, project->parallelTasks);
}

Project* loadFromFileProject(FILE *toRead) {
    Project *project = NULL;

    if (!toRead) return NULL;

    project = (Project*)malloc(sizeof(Project));

    if (!project) {
        printf("\nError in allocation memory in Project!!!\n");
        exit(-1);
    }

    clear(toRead);
    project->projectName = getWordFromFile(toRead);
    clear(toRead);

    fscanf(toRead, " %d", &project->peopleOnProject);

    fscanf(toRead, " %lf", &project->resourcesOnProject);
    clear(toRead);
    /*clear(toRead);*/
    project->criticalTasks = loadFromFileListOfTasks(toRead);
    clear(toRead);
    project->parallelTasks = loadFromFileListOfTasks(toRead);

    project->criticalTasks = project->parallelTasks = NULL;

    return project;
}
