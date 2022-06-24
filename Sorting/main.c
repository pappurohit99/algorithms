  #include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils.h"
#include "sort.h"

int main() {
  int arr[] = {6, 7, 2, 5, 3, 1, 8, 4};
  const int N = sizeof(arr) / sizeof(arr[0]);

  printf("Initial array\n");
  printArray(arr, N, ',');

  selectionSort(arr, N);

  printf("Sorted array\n");
  printArray(arr, N, ',');

  return 0;
}