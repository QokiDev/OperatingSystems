all: compile run

compile: main.c integr.c my_threads.c
	gcc main.c  integr.c my_threads.c -lpthread -o main.out

run: main.out
	./main.out
