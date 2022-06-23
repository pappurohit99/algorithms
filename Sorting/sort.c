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
  assert(n > 0);
  int low = 0;
  int high = n - 1;
  hSplit(input, low, high);
  return input;
}

int* quickSort(int* input, int n) {
  assert(n > 0);
  int low = 0;
  int high = n - 1;
  hQuickSort(input, low, high);
  return input;
}

int* bubbleSort(int* input, int N) {
  assert(N > 0);
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (input[j] > input[j + 1]) {
        swap(&input[j], &input[j + 1]);
      }
    }
  }
  return input;
}

//*****************//
// helper functions//
//*****************//
void hSplit(int* input, int low, int high) {
  int mid;
  if (low < high) {
    mid = low + (high - low) / 2;
    hSplit(input, low, mid);
    hSplit(input, mid + 1, high);
    hMerge(input, low, mid, high);
  }
}

void hMerge(int* arr, int low, int mid, int high) {
  const int N1 = mid - low + 1;
  const int N2 = high - mid;
  int* arr1 = (int*)malloc(N1 * sizeof(int));
  int* arr2 = (int*)malloc(N2 * sizeof(int));

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
  while (i < N1) {
    arr[k++] = arr1[i++];
  }
  while (j < N2) {
    arr[k++] = arr2[j++];
  }
}

void hQuickSort(int* input, int low, int high) {
  if (low < high) {
    // partition and find pivot index
    int mid = hRandomize(input, low, high);
    hQuickSort(input, low, mid - 1);
    hQuickSort(input, mid + 1, high);
  }
}

int hRandomize(int* arr, int low, int high) {
  int idx = low + (rand() % (high -low));
  swap(&arr[idx], &arr[high]);
  return hPartition(arr, low, high);
}

int hPartition(int* arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[j], &arr[i]);
    }
  }

  i++;
  swap(&arr[i], &arr[high]);
  return i;
}
