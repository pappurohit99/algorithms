#ifndef SORT_H
#define SORT_H

// Main functions
int* insertionSort(int* arr, int N);
int* mergeSort(int* arr, int N);
int* quickSort(int* arr, int N);
int* bubbleSort(int* arr, int N);

// helper functions

// Merge sort
void hSplit(int* arr, int low, int high);
void hMerge(int* arr, int low, int mid, int high);

// Quick sort

int hPartition(int* arr, int low, int high);
void hQuickSort(int* arr, int low, int high);
#endif