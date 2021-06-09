#include "Lab7.h"

int main() {
    FILE *file = NULL;
    long int position = 0;
    ListOfProjects *listOfProjects = NULL;

    file = fopen("Projects.txt", "r");
    fseek(file, 0, SEEK_END);
    position = ftell(file);

    fseek(file, 0, SEEK_SET);
    if (position < 50) listOfProjects = newListOfProjects();
    else
        listOfProjects = loadFromFileListOfProjects(file);

    fclose(file);

    file = fopen("Projects.txt", "w");
    saveToFileListOfProjects(file, listOfProjects);
    fclose(file);

    return 0;
}

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
    /*char *nameToDelete = NULL;*/
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
            addProjectEnd(listOfProjects, temp);
            break;
        case 2:
            printProjectShort(listOfProjects);
            break;
        case 3:
            completeProject(listOfProjects); 
            break;
        default:
            break;
        }
    }

    return 1;
}