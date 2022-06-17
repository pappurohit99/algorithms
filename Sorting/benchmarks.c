#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "../utils.h"

int main() {
  // Setup init array

  const int N = 100;
  int* in = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    in[i] = rand() % N;
  }

  // Setup output array
  int* out = NULL;

  clock_t tic, toc;
  double t1, t2, t3, t4;

  printf("Size of array: %d\n", N);

  // Run benchmarks
  tic = clock();
  out = insertionSort(in, N);
  toc = clock();
  t1 = (((double)(toc - tic)) / CLOCKS_PER_SEC) * 1000;

  tic = clock();
  out = mergeSort(in, N);
  toc = clock();
  t2 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  tic = clock();
  out = quickSort(in, N);
  toc = clock();
  t3 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  tic = clock();
  out = bubbleSort(in, N);
  toc = clock();
  t4 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;

  // Print output
  printf("Insertion sort: %lfms\n", t1);
  printf("Merge sort: %lfms\n", t2);
  printf("Quick sort: %lfms\n", t3);
  printf("Bubble sort: %lfms\n", t4);

  return 0;
}