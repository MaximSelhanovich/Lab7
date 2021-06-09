#include "Lab7.h"

int menu(ListOfProjects *listOfProjects) {
    char choise = 0;
    
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


