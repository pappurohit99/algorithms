clean:
	rm -rf derived

build: main

main: utils stack
	gcc -Wall -g main.c derived/*.o -o derived/main.out

utils:
	mkdir -p derived
	gcc -Wall -c -g ../utils.c -o derived/utils.o

stack:
	gcc -Wall -c -g stackImpl.c -o derived/stack.o