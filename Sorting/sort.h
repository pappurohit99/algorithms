#ifndef SORT_H
#define SORT_H

// Main functions
int* insertionSort(int* arr, int N);
int* mergeSort(int* arr, int N);

// helper functions
void split(int* arr, int low, int high);
void merge(int* arr, int low, int mid, int high);
#endif