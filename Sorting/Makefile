clean:
	rm -rf derived

build: main benchmarks

main: utils sorting
	gcc -Wall -g main.c derived/*.o -o derived/main.out

benchmarks: utils sorting
	gcc -Wall -g benchmarks.c derived/*.o -o derived/benchmarks.out

utils:
	[-d derived] || mkdir derived
	gcc -Wall -c -g ../utils.c -o derived/utils.o

sorting:
	gcc -Wall -c -g sort.c -o derived/sort.o