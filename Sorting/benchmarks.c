#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sort.h"
#include "../utils.h"

void copyArr(int* src, int* dest, int n);

int main() {

  // Setup test data
  int n;
  printf("Enter order of magnitude (between 0 to 6): ");
  scanf("%d", &n);
  int N = 100000;
  if (n >= 0 && n <= 6) {
    N = (int)pow(10, n);
  }
  else {
      printf("Defaulting to 10^5\n");
  }

  int* in = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    in[i] = rand() % N;
  }

  // Clone test data
  int* clone = (int*)malloc(N * sizeof(int));

  clock_t tic, toc;
  double t1, t2, t3, t4, t5;

  printf("Size of array: %d\n", N);

  // Run benchmarks
  copyArr(in, clone, N);
  tic = clock();
  mergeSort(clone, N);
  toc = clock();
  t2 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Merge sort: %lfms\n", t2);

  copyArr(in, clone, N);
  tic = clock();
  quickSort(clone, N);
  toc = clock();
  t3 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Quick sort: %lfms\n", t3);
  
  copyArr(in, clone, N);
  tic = clock();
  insertionSort(clone, N);
  toc = clock();
  t1 = (((double)(toc - tic)) / CLOCKS_PER_SEC) * 1000;
  printf("Insertion sort: %lfms\n", t1);

  copyArr(in, clone, N);
  tic = clock();
  bubbleSort(clone, N);
  toc = clock();
  t4 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Bubble sort: %lfms\n", t4);

  copyArr(in, clone, N);
  tic = clock();
  selectionSort(clone, N);
  toc = clock();
  t5 = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Selection sort: %lfms\n", t5);

  free(in);
  free(clone);

  printf("Type quit to exit\n");
  char s[10];
  scanf("%s", s);

  return 0;
}

void copyArr(int* src, int* dest, int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}