clean:
	rm -rf derived

build: main

main: stack list
	gcc -Wall -g main.c derived/*.o -o derived/main.out

utils:
	mkdir -p derived
	gcc -Wall -c -g ../utils.c -o derived/utils.o

stack: utils
	gcc -Wall -c -g stackImpl.c -o derived/stack.o

list: utils
	gcc -Wall -c -g listImpl.c -o derived/list.o