#ifndef SORT_H
#define SORT_H

// Main functions
int* insertionSort(int* arr, int N);
int* mergeSort(int* arr, int N);
int* bubbleSort(int* arr, int N);

// helper functions
void hSplit(int* arr, int low, int high);
void hMerge(int* arr, int low, int mid, int high);
#endif