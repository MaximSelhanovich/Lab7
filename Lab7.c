#include "Lab7.h"

int completeProject(ListOfProjects *listOfProjects) {
    char *nameToDelete = NULL;
    Project *temp = NULL;

    if (!listOfProjects || !listOfProjects->head) return 0;

    printf("\nEnter name to \"complete\" project\n");
    nameToDelete = getWord();
    temp = deleteProjectInList(listOfProjects, nameToDelete);

    if (!temp) {
        printf("There ir no project with name %s", nameToDelete);
        return 0;
    } else {
        printProject(temp);
        deleteProject(temp);
    }

    return 1;
}

int menu(ListOfProjects *listOfProjects) {
    char choise = 0;
    char *nameToDelete = NULL;
    Project *temp = NULL;

    if (!listOfProjects) return INT_MIN;

    while (choise != 4) {
        printf("Make your choise\n"
               "1)Add project\n"
               "2)View all projects\n"
               "3)Complete project\n"
               "4)Exit\n");

        choise = getValidInt(1, 4);
        
        switch (choise)
        {
        case 1:
            temp = newProject();
            addProjetcEnd(listOfProjects, temp);
            break;
        case 2:
            printProjectNames(listOfProjects);
            break;
        case 3:
            completeProject(listOfProjects); 
            break;
        default:
            break;
        }
    }
}

int main() {
    FILE *file = NULL;
    long long position = 0;
    ListOfProjects *listOfProjects = NULL;
    file = fopen("Projects.txt", "r");
    fseek(file, 0, SEEK_END);
    position = ftell(file);
    if (position < 50) listOfProjects = newListOfTasks();
    else
        listOfProjects = loadFromFileListOfProjects(file);

    


    fclose(file);

    file = fopen("Projects.txt", "w");
    saveToFileListOfProjects(file, listOfProjects);
    fclose(file);

    return 0;
}


