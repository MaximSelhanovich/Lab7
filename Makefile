CC = gcc
CFLAGS = -std=c89 -pedantic -Wall
LIBS = 
OBJ = Lab7.c Project.c ListOfTasks.c Task.c Date.c ListOfProjects.c 
OBJ_TEST = Lab7_Test.c $(OBJ)
CPPLINTFLAGS = --filter=-readability/casting,-legal/copyright,-runtime/int

Lab7: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o Lab7

Lab7_Test: $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o Lab7_Test -Dmain=_main -fprofile-arcs -ftest-coverage -lgcov -g $(LIBS)
Valgrind:
	echo "321\n2024\n-4\n2\nasdf\n29\n2022\n5\n28\n2026\n6\n30\n2026\n6\n30\nGet rekted\n2222\n2\n2\n" > input.txt
	echo "2222\n1\n1\n2345\n2\n2\nArchitector\n2211\n12\n30\n2222\n5\n18\nDomachnee zadanie\n2022\n02\n21\n2030\n09\n30\nZhmuh\n2057\n9\n3\n2089\n6\n2\nOcheredi\n2045\n8\n3\n2046\n8\n3\nKursach\n2021\n6\n7\n2021\n6\n8\nProjext test\n678\n3\nTest\n789\n32\nKek\n543\n67\nnoooooo\n78\n09\n" >> input.txt
	valgrind ./Lab7_Test < input.txt

CheckLinter:
	cpplint $(CPPLINTFLAGS) $(OBJ_TEST)

all: Lab7 Lab7_Test Valgrind CheckLinter

.PHONY: clean
clean:
	del *.exe
