program: main.o stack.o stack.h
	gcc  main.o stack.o -o program
main.o: stack.h main.c
	gcc  main.c -c
stack.o: stack.h stack.c 
	gcc  stack.c -c