#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

int* insertionSort(int*, int);

int main() {
  int in[] = {6, 8, 1, 4, 5, 3, 7, 2};
  const int N = sizeof(in) / sizeof(in[0]);
  int* out = NULL;
  out = insertionSort(in, N);

  printf("initial array: ");
  for (int i = 0; i < N; i++) {
    printf("%d, ", in[i]);
  }
  printf("\nsorted array: ");
  for (int i = 0; i < N; i++) {
    printf("%d, ", out[i]);
  }
  return 0;
}

int* insertionSort(int* input, int n) {
  assert(n > 0);

  // Initialize sorted array
  int* arr = (int*)malloc(n * sizeof(int));

  // Initialize first value
  arr[0] = input[0];
  for (int i = 1; i < n; i++) {
    arr[i] = input[i];
    int j = i;
    while (j--) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      } else {
      	break;
      }
    }
  }
  return arr;
}