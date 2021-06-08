#include "Lab7.h"

int main() {
    Task *new = getTask();
    printTask(new);

    deleteTask(new);

    return 0;
}
