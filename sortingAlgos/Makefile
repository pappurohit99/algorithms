CFLAGS = -Wall -g -std=c11 -fdiagnostics-color=always

clean:
	rm -rf derived

build: main benchmarks

main: sorting
	clang $(CFLAGS) main.c derived/*.o -o derived/main.out

benchmarks: sorting
	clang $(CFLAGS) benchmarks.c derived/*.o -o derived/benchmarks.out

utils:
	mkdir -p derived
	clang $(CFGLAGS) -c ../utils.c -o derived/utils.o

sorting: utils
	clang $(CFLAGS) -c sort.c -o derived/sort.o
