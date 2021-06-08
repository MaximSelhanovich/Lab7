#include "Project.h"

typedef struct ListOfProjects {
    Project *head;
    Project *tail;

    unsigned int length;
}ListOfProjects;

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