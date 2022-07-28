#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"
#include "../utils.h"

void copyArr(int *src, int *dest, int n);

int main()
{

  // Setup test data
  int n;
  printf("Enter order of magnitude (between 0 to 6): ");
  scanf("%d", &n);
  int N = (int)pow(10, 4);
  if (n >= 0 && n <= 6)
  {
    N = (int)pow(10, n);
  }
  else
  {
    N = 4;
    printf("Defaulting to 10^4\n");
  }

  int highMag = N > 4;

  int *in = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++)
  {
    in[i] = rand() % N;
  }

  // Clone test data
  int *clone = (int *)malloc(N * sizeof(int));

  clock_t tic, toc;
  double t;

  printf("Size of array: %d\n", N);

  // Run benchmarks
  copyArr(in, clone, N);
  tic = clock();
  mergeSort(clone, N);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Merge sort: %lfms\n", t);

  copyArr(in, clone, N);
  tic = clock();
  quickSort(clone, N);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Quick sort: %lfms\n", t);

  copyArr(in, clone, N);
  tic = clock();
  heapSort(clone, N);
  toc = clock();
  t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
  printf("Heap sort: %lfms\n", t);

  // Slower sorts

  if (!highMag)
  {
    copyArr(in, clone, N);
    tic = clock();
    insertionSort(clone, N);
    toc = clock();
    t = (((double)(toc - tic)) / CLOCKS_PER_SEC) * 1000;
    printf("Insertion sort: %lfms\n", t);

    copyArr(in, clone, N);
    tic = clock();
    bubbleSort(clone, N);
    toc = clock();
    t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
    printf("Bubble sort: %lfms\n", t);

    copyArr(in, clone, N);
    tic = clock();
    selectionSort(clone, N);
    toc = clock();
    t = ((double)(toc - tic)) / CLOCKS_PER_SEC * 1000;
    printf("Selection sort: %lfms\n", t);
  }
  else
  {
    printf("Skipping Insertion sort..\nSkipping Bubble sort..\nSkipping Selection sort\n");
  }

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