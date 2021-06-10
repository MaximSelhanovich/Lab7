#include "Date.h"
#include "Task.h"
#include "ListOfTasks.h"
#include "ListOfProjects.h"
#include <assert.h>
#include <string.h>

void testgetDate() {
    /*321\n2024\n-4\n2\nasdf\n29\n*/
    Date *test = getDate();
    assert(test);
    assert(test->year == 2024);
    assert(test->month == 2);
    assert(test->day == 29);

    assert(printDate(test));
    assert(!printDate(NULL));

    deleteDate(test);
}

void testgetMaxDay() {
    assert(getMaxDay(-4) == INT_MIN);
    assert(getMaxDay(4) == 30);
    assert(getMaxDay(2) == 28);
    assert(getMaxDay(5) == 31);
}

void testdifDate() {
    /*2022\n5\n28\n*/
    Date *test1 = getDate();
    /*2026\n6\n30\n*/
    Date *test2 = getDate();
    /*2026\n6\n30\n*/

    printf("\n%d\n", difDate(test1, test2));
    assert(difDate(test1, test2) == 1494);
    assert(difDate(NULL, test2) == INT_MIN);
    assert(difDate(test1, NULL) == INT_MIN);
    assert(difDate(NULL, NULL) == INT_MIN);

    assert(compareDate(test1, test2) == -1);
    assert(compareDate(test2, test1) == 1);

    rewriteDate(test1);

    assert(!compareDate(test2, test1));

    deleteDate(test1);
    deleteDate(test2);
}

void testgetTask() {
    /*Get rekted\n2222\n2\n2\n2222\n1\n1\n2345\n2\n2\n*/
    Task *task = getTask();

    assert(!strcmp(task->taskName, "Get rekted"));

    assert(task->startTaskTime->year == 2222);
    assert(task->startTaskTime->month == 2);
    assert(task->startTaskTime->day == 2);

    printTask(task);
    assert(task->endTaskTime->year == 2345);
    assert(task->endTaskTime->month == 2);
    assert(task->endTaskTime->day == 2);

    assert(!printTask(NULL));
    assert(printTask(task));

    deleteTask(task);
}

void testListOfTasks() {
    ListOfTasks *list = newListOfTasks();
    Task *task1 = NULL;
    Task *task2 = NULL;
    Task *task3 = NULL;
    Task *task4 = NULL;
    Task *task5 = NULL;

    /*Architector\n2211\n12\n30\n2222\n5\n18\n*/
    task1 = getTask();
    addTaskEnd(list, task1);

    /*Domachnee zadanie\n2022\n02\n21\n2030\n09\n30\n*/
    task2 = getTask();
    addTaskFront(list, task2);

    /*Zhmuh\n2057\n9\n3\n2089\n6\n2\n*/
    task3 = getTask();
    addTask(list, task3);

    /*Ocheredi\n2045\n8\n3\n2046\n8\n3\n*/
    task4 = getTask();
    addTask(list, task4);

    /*Kursach\n2021\n6\n7\n2021\n6\n8\n*/
    task5 = getTask();
    addTask(list, task5);

    assert(printListOfTasks(list));

    assert(searchTask(list, "Zhmuh"));
    assert(!searchTask(NULL, "Zhmuh"));
    assert(!searchTask(list, NULL));
    assert(!searchTask(NULL, NULL));

    assert(!strcmp(list->head->taskName, "Kursach"));
    removeTaskFront(list);
    assert(!strcmp(list->head->taskName, "Domachnee zadanie"));

    assert(!strcmp(list->tail->taskName, "Architector"));
    removeTaskEnd(list);
    assert(!strcmp(list->tail->taskName, "Zhmuh"));

    assert(searchTask(list, "Ocheredi"));
    /**/
    task1 = deleteTaskInList(list, "Ocheredi");
    assert(!strcmp(task1->taskName, "Ocheredi"));
    deleteTask(task1);

    task2 = deleteTaskInList(list, "Doesn't exist");
    assert(!task2);

    task3 = deleteTaskInList(list, "Zhmuh");
    assert(!strcmp(task3->taskName, "Zhmuh"));
    deleteTask(task3);

    task4 = deleteTaskInList(list, "Domachnee zadanie");
    assert(!strcmp(task4->taskName, "Domachnee zadanie"));
    deleteTask(task4);

    assert(printListOfTasks(list));
    assert(!printListOfTasks(NULL));

    deleteListOfTasks(list);
}

void testListOFProjects() {
    ListOfProjects *list = newListOfProjects();
    /*Projext test\n678\n3\n*/
    Project *project1 = newProject();
    /*Test\n789\n32\n*/
    Project *project2 = newProject();
    /*Kek\n543\n67\n*/
    Project *project3 = newProject();
    /*noooooo\n78\n09\n*/
    Project *project4 = newProject();
    /*Vabalabadabdab\n963\n8\n*/
    /*Project *project5 = newProject();*/

    /*assert(!strcmp(project1->projectName, "Projext test"));
    assert(project2->peopleOnProject == 789);
    assert(project3->resourcesOnProject == 67);
    assert(!strcmp(project4->projectName, "noooooo"));
    assert(project5->peopleOnProject == 963);*/

    addProjectEnd(list, project1);
    assert(list->head->peopleOnProject == 678);
    addProjectFront(list, project2);
    assert(list->head->resourcesOnProject == 32);
    addProjectEnd(list, project3);
    assert(!strcmp(list->tail->projectName, "Kek"));
    addProjectFront(list, project4);
    assert(list->head->peopleOnProject == 78);

    /*1\nZhmuh\n2057\n9\n3\n2089\n6\n2\n3\n*/
    /*addTaskInProject(project5);*/
    /*2\nDomachnee zadanie\n2022\n02\n21\n2030\n09\n30\n3\n*/
    /*addTaskInProject(project5);*/
    /*3\n*/
    /*addTaskInProject(project5);*/

    /*assert(printDeadlines(project5));*/
    assert(!printDeadlines(NULL));

    /*assert(printProjectShort(list));*/
    assert(!printProjectShort(NULL));

    /*assert(printProject(project5));*/
    assert(!printProject(NULL));

    /*assert(!deleteTaskInProject(project5, "Loop"));
    assert(deleteTaskInProject(project5, "Domachnee zadanie"));
    assert(deleteTaskInProject(project5, "Zhmuh"));*/

    /*assert(deleteProject(project5));*/
    assert(!deleteProject(NULL));

    project1 = deleteProjectInList(list, "jdfgvrtjyg");
    assert(!project1);

    project2 = deleteProjectInList(list, "Projext test");
    assert(project2);
    deleteProject(project2);

    project3 = deleteProjectInList(list, "Kek");
    assert(project3);
    deleteProject(project3);

    project4 = deleteProjectInList(list, "noooooo");
    assert(project4);
    deleteProject(project4);

    deleteListOfProjects(list);
}

#undef main

int main() {
    testgetDate();
    testgetMaxDay();
    testdifDate();
    testgetTask();
    testListOfTasks();
    testListOFProjects();
    return 0;
}
