all: compile run

compile: main.c tarray.c task.c threads.c
	gcc main.c tarray.c task.c threads.c -lpthread  -o ./main.out

run: main.out
	./main.out
