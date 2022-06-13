#include <stdio.h>

#include "sort.h"

int main() {
  // Setup init array
  int in[] = {6, 8, 1, 4, 3, 7, 2, 5};
  const int N = sizeof(in) / sizeof(in[0]);
  int *out = NULL;

  printf("initial array: ");
  for (int i = 0; i < N; i++) {
    printf("%d, ", in[i]);
  }

  // Perform sort
  out = mergeSort(in, N);

  printf("\nsorted array: ");
  for (int i = 0; i < N; i++) {
    printf("%d, ", out[i]);
  }
  printf("\n");

  return 0;
}