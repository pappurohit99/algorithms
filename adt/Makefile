CFLAGS = -Wall -g -std=c11

clean:
	rm -rf derived

build: stack list
	gcc $(CFLAGS) main.c derived/*.o -o derived/main.out

utils:
	mkdir -p derived
	gcc $(CFLAGS) -c ../utils.c -o derived/utils.o

stack: utils
	gcc $(CFLAGS) -c stackImpl.c -o derived/stack.o

list: utils
	gcc $(CFLAGS) -c listImpl.c -o derived/list.o
