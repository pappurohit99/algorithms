CFLAGS = -Wall -g -std=c11 -fdiagnostics-color=always

clean:
	rm -rf derived

build: main benchmarks

main: sorting
	gcc $(CFLAGS) main.c derived/*.o -o derived/main.out

benchmarks: sorting
	gcc $(CFLAGS) benchmarks.c derived/*.o -o derived/benchmarks.out

utils:
	mkdir -p derived
	gcc $(CFGLAGS) -c ../utils.c -o derived/utils.o

sorting: utils
	gcc $(CFLAGS) -c sort.c -o derived/sort.o