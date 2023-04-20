# Release
```shell
pappurohit@Mac-Aloo-Tikki sortingAlgos % make benchmarks
mkdir -p derived
clang  -c ../utils.c -o derived/utils.o
clang -Wall -std=c11 -fdiagnostics-color=always -c sort.c -o derived/sort.o
clang -Wall -std=c11 -fdiagnostics-color=always benchmarks.c derived/*.o -o derived/benchmarks.out
pappurohit@Mac-Aloo-Tikki sortingAlgos % ./derived/benchmarks.out
Enter order of magnitude (between 0 to 6): 6
Size of array: 1000000
Merge sort: 320.878000ms
Quick sort: 201.022000ms
Heap sort: 356.452000ms
Skipping Insertion sort..
Skipping Bubble sort..
Skipping Selection sort
Type quit to exit
```

# Debug
```shell
pappurohit@Mac-Aloo-Tikki sortingAlgos % make benchmarks DEBUG=1 
mkdir -p derived
clang  -c ../utils.c -o derived/utils.o
clang -Wall -std=c11 -fdiagnostics-color=always -g -fsanitize=address -fno-omit-frame-pointer -o1 -c sort.c -o derived/sort.o
clang -Wall -std=c11 -fdiagnostics-color=always -g -fsanitize=address -fno-omit-frame-pointer -o1 benchmarks.c derived/*.o -o derived/benchmarks.out
pappurohit@Mac-Aloo-Tikki sortingAlgos % ./derived/benchmarks.out
Enter order of magnitude (between 0 to 6): 6
Size of array: 1000000
Merge sort: 1251.059000ms
Quick sort: 221.126000ms
Heap sort: 437.683000ms
Skipping Insertion sort..
Skipping Bubble sort..
Skipping Selection sort
Type quit to exit
```