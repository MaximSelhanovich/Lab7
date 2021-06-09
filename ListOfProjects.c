#include "ListOfProjects.h"

ListOfProjects* newListOfProjects() {
    ListOfProjects *list = (ListOfProjects*)malloc(sizeof(ListOfProjects));

    if (!list) {
        printf("\nError in memory allocation in \"ListOfTasks\"\n");
        exit(1);
    }

    list->head = list->tail = NULL;
    list->length = 0;

    return list;
}

void printProjectShort(ListOfProjects *list) {
    Project *temp = NULL;

    if (!list) return;

    temp = list->head;

    while (temp) {
        printf("%s", temp->projectName);
        printDeadlines(temp);
    }
}

void addProjectEnd(ListOfProjects *list, Project *newProject) {
    if (!list || !newProject) return;

    if (!list->head) {
        list->head = newProject;
    } else {
        newProject->prevProject = list->tail;
        list->tail->nextProject = newProject;
    }

    ++list->length;
    list->tail = newProject;
}

void addProjectFront(ListOfProjects *list, Project *newProject) {
    if (!list || !newProject) return;

    if (!list->head) {
        list->tail = newProject;
    } else {
        newProject->nextProject = list->head;
        list->head->prevProject = newProject;
    }

    ++list->length;
    list->head = newProject;
}

Project *deleteProjectInList(ListOfProjects *list, const char *nameToSearch) {
    Project *temp = NULL;

    if (!list || !list->head || !nameToSearch) return NULL;

    temp = list->head;

    while (temp) {
        if (!strcmp(temp->projectName, nameToSearch)) {
            printProject(temp);
            
            if (temp == list->head) {
                list->head = list->head->nextProject;
                if (list->head) list->head->prevProject = temp->prevProject;
            } else if (temp == list->tail) {
                list->tail = list->tail->prevProject;
                if (list->tail) list->tail->nextProject = temp->nextProject;
            } else {
                temp->prevProject->nextProject = temp->nextProject;
                temp->nextProject->prevProject = temp->prevProject; 
            }
            
            temp->nextProject = temp->prevProject = NULL;
            return temp;
        }
        temp = temp->nextProject;
    }
    return NULL;
}

void deleteListOfProjects(ListOfProjects *list) {
    Project *temp = NULL;
    
    if (!list) return;

    temp = list->head;

    while (temp) {
        temp = list->head->nextProject;
        deleteProject(list->head);
        list->head = temp;
    }

    free(list);
}

void saveToFileListOfProjects(FILE *toWrite, ListOfProjects *list) {
    Project *temp = NULL;

    if (!toWrite || !list) return;

    temp = list->head;
    fprintf(toWrite, "%d\n", list->length);

    while (temp) {
        saveToFileProject(toWrite, temp);
        temp = temp->nextProject;
    }
}

ListOfProjects* loadFromFileListOfProjects(FILE *toRead) {
    ListOfProjects *list = NULL;
    Project *project = NULL;
    int i = 0;
    unsigned int length = 0;

    if (!toRead) return NULL;

    list = newListOfProjects();
    fscanf(toRead, "%u", &length);

    for (i = 0; i < length; ++i) {
        project = loadFromFileProject(toRead);
        addProjectEnd(list, project);
    }

    return list;
}