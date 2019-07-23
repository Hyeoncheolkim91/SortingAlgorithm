#ifndef __SORTINGALGO__
#define __SORTINGALGO__

void InsertionSort(int * arr, int size);
void SelectionSort(int * arr, int size);
void QuickSort(int * arr, int size);
void doQuickSort(int *arr, int left, int right);
int partition(int * arr, int left, int right);

void MergeSort(int * arr, int size);
void doMergeSort(int * arr, int left, int right);
void MergeTwoArea(int * arr, int left, int mid, int right);

void HeapHeapify(int * arr, int size, int i);
void HeapSort(int * arr, int size);
void RadixSort(int * arr, int size);
#endif