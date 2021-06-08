#include "Project.h"

typedef struct ListOfProjects {
    Project *head;
    Project *tail;

    unsigned int length;
}ListOfProjects;

void printProjectNames(ListOfProjects *list) {
    Project *temp = NULL;

    if (!list) return;

    temp = list->head;

    while (temp) {
        printf("%s", temp->projectName);
    }
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