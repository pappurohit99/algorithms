#include "sort.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"

int* insertionSort(int* input, int n) {
  assert(n > 0);

  // Initialize sorted array
  int* arr = (int*)malloc(n * sizeof(int));

  // Initialize first value
  arr[0] = input[0];
  for (int i = 1; i < n; i++) {
    arr[i] = input[i];
    int j = i;
    while (j-- && arr[j] > arr[j + 1]) {
      swap(&arr[j], &arr[j + 1]);
    }
  }
  return arr;
}

int* mergeSort(int* input, int n) {
  int low = 0;
  int high = n - 1;
  split(input, low, high);
  return input;
}

//*****************//
// helper functions//
//*****************//
void split(int* input, int low, int high) {
  int mid;
  if (low < high) {
    mid = low + (high - low) / 2;
    split(input, low, mid);
    split(input, mid + 1, high);
    merge(input, low, mid, high);
  }
}

void merge(int* arr, int low, int mid, int high) {
  const int N1 = mid - low + 1;
  const int N2 = high - mid;
  // int* arr1 = (int*)malloc(N1 * sizeof(int));
  // int* arr2 = (int*)malloc(N2 * sizeof(int));
  int arr1[N1], arr2[N2];

  // Initialize sub arrays
  for (int i = 0; i < N1; i++) {
    arr1[i] = arr[low + i];
  }
  for (int i = 0; i < N2; i++) {
    arr2[i] = arr[mid + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = low;
  while (i < N1 && j < N2) {
    if (arr1[i] < arr2[j]) {
      arr[k++] = arr1[i];
      i++;
    } else if (arr2[j] < arr1[i]) {
      arr[k++] = arr2[j];
      j++;
    } else {
      arr[k++] = arr1[i];
      arr[k++] = arr2[j];
      i++;
      j++;
    }
  }
  while (i<N1) {
    arr[k++] = arr1[i++];
  }
  while (j<N2) {
    arr[k++] = arr2[j++];
  }
}