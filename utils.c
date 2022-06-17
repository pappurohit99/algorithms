#include "utils.h"
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int *arr, int n, char separator) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d%c ", arr[i], separator);
  }
  if (n > 0) {
    // print last element
    printf("%d\n", arr[n - 1]);
  }
}