#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "sort.h"
#include "../utils.h"

void copyArr(int *src, int *dest, int n);

int main()
{
  // Declare variables
  clock_t tic, toc;
  double t;
  int numel, order;

  // declare constants
  int const DEFAULT_ORDER = 5;
  int const MIN_ORDER = 0;
  int const MAX_ORDER = 6;

  int const DEFAULT_NO_ELEMENTS = (int)(pow(10, DEFAULT_ORDER));

  // Setup test data
  printf("Enter order of magnitude (between 0 to 6): ");
  scanf("%d", &order);
  if (order >= MIN_ORDER && order <= MAX_ORDER)
  {
    numel = (int)(pow(10, order));
  }
  else
  {
    numel = DEFAULT_NO_ELEMENTS;
    printf("Defaulting to %d as number of elements\n", numel);
  }

  int *in = (int *)malloc(numel * sizeof(int));
  for (int i = 0; i < numel; i++)
  {
    in[i] = rand() % numel;
  }

  // Clone test data
  int *clone = (int *)malloc(numel * sizeof(int));

  printf("Size of array: %d\n", numel);

  // Run benchmarks

  // Merge sort
  copyArr(in, clone, numel);
  tic = clock();
  mergeSort(clone, numel);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Merge sort: %lf ms\n", t);

  // Quick sort
  copyArr(in, clone, numel);
  tic = clock();
  quickSort(clone, numel);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Quick sort: %lf ms\n", t);

  // Heap sort
  copyArr(in, clone, numel);
  tic = clock();
  heapSort(clone, numel);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Heap sort: %lf ms\n", t);

  // Slower sorts

  // Reallocate if too many elements
  if (order > DEFAULT_ORDER)
  {
    numel = DEFAULT_NO_ELEMENTS;
    clone = realloc(clone, numel * sizeof(int));
    printf("Downsizing sample to %d for performance reasons\n", numel);
  }

  copyArr(in, clone, numel);
  tic = clock();
  insertionSort(clone, numel);
  toc = clock();
  t = (((double)(toc - tic)) / CLOCKS_PER_SEC) * 1000;
  printf("Insertion sort: %lf ms\n", t);

  copyArr(in, clone, numel);
  tic = clock();
  bubbleSort(clone, numel);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Bubble sort: %lf ms\n", t);

  copyArr(in, clone, numel);
  tic = clock();
  selectionSort(clone, numel);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Selection sort: %lf ms\n", t);

  free(in);
  free(clone);

  printf("Type quit to exit\n");
  char s[10];
  scanf("%s", s);

  return 0;
}

// Utility function to copy elements from source array to destination array
void copyArr(int *src, int *dest, int n)
{
  for (int i = 0; i < n; i++)
  {
    dest[i] = src[i];
  }
}