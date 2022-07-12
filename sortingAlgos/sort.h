#ifndef SORT_H
#define SORT_H

// Main APIs
void insertionSort(int *arr, int N);
void mergeSort(int *arr, int N);
void quickSort(int *arr, int N);
void bubbleSort(int *arr, int N);
void selectionSort(int *arr, int N);
void heapSort(int *arr, int N);

// helper functions

// Merge sort
void hSplit(int *arr, int low, int high);
void hMerge(int *arr, int low, int mid, int high);

// Quick sort
int hPartition(int *arr, int low, int high);
int hRandomize(int *arr, int low, int high);
void hQuickSort(int *arr, int low, int high);

// Selection sort
int minIndex(int *arr, int start, int end);

// Heap sort
void heapify(int *arr, int n, int i);

#endif