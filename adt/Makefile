CFLAGS = -Wall -g -std=c11 -fdiagnostics-color=always

clean:
	rm -rf derived

build: stack list
	clang $(CFLAGS) main.c derived/*.o -o derived/main.out

utils:
	mkdir -p derived
	clang $(CFLAGS) -c ../utils.c -o derived/utils.o

stack: utils
	clang $(CFLAGS) -c stackImpl.c -o derived/stack.o

list: utils
	clang $(CFLAGS) -c listImpl.c -o derived/list.o
