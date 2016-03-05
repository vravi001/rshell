#CC = g++
#CC_FLAGS = -Wall -Werror -ansi -pedantic
#all: main.out
#main.out: main.o
#	$(CC) main.o -o main.out
#main.o: main.cpp
#	$(CC) $(CC_FLAGS) main.cpp
#rshell: main.out
#main.out: main.o
#	$(CC) main.o -o main.out
#main.o: main.cpp
#	$(CC) $(CC_FLAGS) main.cpp
#clean
#	rm *o main.out
#all: main.out
##a.out: rshell.out 
##	g++ rshell.o
##rshell.out: rshell.cpp
##	g++ -Wall -Werror -ansi -pedantic rshell.cpp
#rshell: main.out
#main.out: main.cpp
#	g++ -Wall -Werror -ansi -pedantic main.cpp
make: rshell.cpp
	g++ -Wall -Werror -ansi -pedantic rshell.cpp -o rshell.out

