#include "Lab7.h"

int main() {
    FILE *file = NULL;
    ListOfProjects *listOfProjects = NULL;

    file = fopen("Projects.txt", "r");
    if (!file) {
        printf("\nError in openning file\n");
        exit(-1);
    }

    if (getc(file) != EOF) {
        fseek(file, 0, SEEK_SET);
        listOfProjects = loadFromFileListOfProjects(file);
    } else {
        listOfProjects = newListOfProjects();
    }

    menu(listOfProjects);

    fclose(file);

    file = fopen("Projects.txt", "w");
    saveToFileListOfProjects(file, listOfProjects);
    fclose(file);

    return 0;
}

Project* workWithProject(Project* project) {
    Task *activeTask = NULL;
    char choise = 0;
    char *nameToSearch = NULL;

    if (!project) return NULL;
    
    while (choise != 5) {
        printf("Make your choise\n"
               "1)Add critical task\n"
               "2)Add parallel task\n"
               "3)Complete task\n"
               "4)Complete this project\n"
               "5)Exit\n");

        choise = getValidInt(1, 5);
        switch(choise) {
        case 1:
            activeTask = getTask();
            addTask(project->criticalTasks, activeTask);
            break;
        case 2:
            activeTask = getTask();
            addTask(project->parallelTasks, activeTask);
            break;
        case 3:
            nameToSearch = getWord();
            activeTask = deleteTaskInProject(project, nameToSearch);
            if (activeTask) deleteTask(activeTask);
            else 
                printf("There is no such task in project");

            free(nameToSearch);
            break;
        case 4:
            deleteProject(project);
            return NULL;
            break;
        default:
            break;
        }
    }

    return project;
}

int menu(ListOfProjects *listOfProjects) {
    char choise = 0;
    char *nameToDelete = NULL;
    Project *activeProject = NULL;

    if (!listOfProjects) return INT_MIN;

    while (choise != 4) {
        printf("Make your choise\n"
               "1)Add project\n"
               "2)View all projects\n"
               "3)Work with project\n"
               "4)Exit\n");

        choise = getValidInt(1, 4);

        switch (choise) {
        case 1:
            activeProject = newProject();
            addProjectEnd(listOfProjects, activeProject);
            break;
        case 2:
            printProjectShort(listOfProjects);
            break;
        case 3:
            nameToDelete = getWord();
            activeProject = deleteProjectInList(listOfProjects, nameToDelete);

            if (activeProject) {
                activeProject =  workWithProject(activeProject);
            } else {
                printf("\nThere is no such project");
            }

            if (activeProject) addProjectEnd(listOfProjects, activeProject);
            free(nameToDelete);
            break;
        default:
            break;
        }
    }

    return 1;
}
