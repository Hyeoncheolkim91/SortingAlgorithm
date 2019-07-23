#include<iostream>
#include<chrono>
#include"ArrayList.h"
#include"Sorting.h"
#include"SortingHelper.h"
#include<list>
#include<cmath>

using namespace std;

unsigned int compare = 0;	//Global count variable for comparison
unsigned int movement = 0;	//Global count variable for movement

//initialize count variables'
void initCount() {  
	compare = 0; 
	movement = 0;
}

//Insertion sort
void InsertionSort(int * arr, int size) {
	

	int * temparr = new int[size];
	for (int i = 0; i < size; i++)
		temparr[i] = arr[i];

	for (int i = 1; i < size; i++) {
		int j;
		int key = temparr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temparr[j] > key) {
				compare++;
				temparr[j + 1] = temparr[j];
				movement++;
			}
			else {
				compare++;
				break;
			}
		}
		temparr[j + 1] = key;

	}
	
	cout << endl;
	cout << "------Insertion Sort result" << endl;
	cout << "Movement: " << movement << "\t" << "Comparison: " << compare << endl;
	
	initCount();
	delete[] temparr;
}

void SelectionSort(int * arr, int size)
{

	int * temparr = new int[size];	//create temp array 
	for (int i = 0; i < size; i++)
		temparr[i] = arr[i];
	
	

	int i, j;
	int min;
	int temp;
	for (i = 0; i < size - 1; i++)
	{
		min = i;		// index i is  for setting minimum value for each cycle
		for (j = i + 1; j < size; j++)   
		{
				
			if (temparr[j] < temparr[min])	//if element in j index is smaller than minimum
				min = j;					// set j as index of minimum 
			
			compare++;						//count comparaison #1
		}
		if (temparr[min] == temparr[i]) {
			movement--;						// if minimum value is not changed, no need to move
											// so it is offset 
		}
		
			temp = temparr[i];			//after cycle, move minimum value into sorted area 				
			temparr[i] = temparr[min];	
			temparr[min] = temp;
			movement++;
			
		
	}
	
	cout << endl;
	cout << "------Selection Sort result" << endl;
	cout << "Movement: " << movement <<"\t"<< "Comparison: " <<compare<<endl;
	initCount();
	delete[] temparr;
}

int partition(int * arr, int left, int right) {
	
	
	int mid = (left + right) / 2; //to make middle element as pivot
	swap(arr[left], arr[mid]); //move middle element to start position
	int pivot = arr[left]; //Set pivot value from mid
	int endofleft = left; // to move from end of left
	
	for (int i = left + 1; i <= right; i++) {	// i starts from right next to pivot
		compare++;						//do compare each cycle
		if (arr[i] < pivot) {			// if the element in i index  less than pivot

			endofleft++;				//increment for next left index
			swap(arr[endofleft],arr[i]);  // move it to the left side
			movement++;						// increment exchange
		}
	
	}
	swap(arr[left], arr[endofleft]); //After partition, it found where pivot has to move
	movement++;					// exchange it
	
	return endofleft; // return new sub-pivot

}
void doQuickSort(int * arr, int left, int right) {
	if (left < right) {
		int pivot = partition(arr, left, right); //Get pivot from partitioning
		doQuickSort(arr, left, pivot - 1); // recursively sort the left sub-array
		doQuickSort(arr, pivot + 1, right); // recusively sort right side of sub-array.
	}
}
void QuickSort(int * arr, int size) {
	int * temparr = new int[size];				//create temp array
	for (int i = 0; i < size; i++) {		
		temparr[i] = arr[i];
	}

	doQuickSort(temparr, 0, size - 1);		// passing index and do quick sort
	
	cout << endl;
	cout << "------QuickSort result" << endl;
	cout << "Movement: " << movement << "\t" << "Comparison: " << compare << endl;
	
	
	initCount();
	delete[] temparr;
}


void MergeTwoArea(int * arr, int left, int mid, int right)
{
	int fIdx = left; // index for left sorted array
	int rIdx = mid + 1; //index of right sorted array
	int i;

	int * sortArr = new int[sizeof(int)*(right + 1)];	 // create temp array
	
	int sIdx = left; //index for array that will be sorted.
	
	 //merge the sorted list
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx]) {
			sortArr[sIdx] = arr[fIdx++];
			movement++;
		}
		else {
			sortArr[sIdx] = arr[rIdx++];
			movement++;
		}
		sIdx++;
		compare++;
	}
	// copy the remaining values
	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++) {
			sortArr[sIdx] = arr[i];
			movement++;
		}
	}
	// copy the remaining values
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++) {
			sortArr[sIdx] = arr[i];
			movement++;
		}
	}
	//re-copy to real array from temporary array.
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete [] sortArr; //delete temp array
}

void doMergeSort(int * arr, int left, int right)
{
	int mid;

	if (left < right) 
	{
		mid = (left + right) / 2; // calculate midpoint
		

		
		doMergeSort(arr, left, mid);	// recursively divide the array of left side
		doMergeSort(arr, mid + 1, right);	//recursively divide the array of right side
												// untill it leaves one element per division.


		MergeTwoArea(arr, left, mid, right);	// recursively Merge divided arrays with sorting.

		
	}
}

void MergeSort(int * arr, int size) {

	int * temparr = new int[size];		// create temp array 
	for (int i = 0; i < size; i++) {	
		temparr[i] = arr[i];
	}
	
	doMergeSort(temparr, 0, size-1); //calling merge sort
	

	cout << endl;
	cout << "------MergeSort result" << endl;
	cout << "Movement: " << movement << "\t" << "Comparison: " << compare << endl;
	
	
	initCount();
	delete[]temparr;
}



void HeapHeapify(int * arr, int size, int i) {
	int left = 2 * i + 1;	
	int right = 2 * i + 2;  
	int largest = i;
	if (left<size && arr[left]>arr[largest]) {
		compare++;
		largest = left;
	}
	if (right<size && arr[right]>arr[largest]) {
		largest = right;
		compare++;
	}
	if (largest == i)
		return;
	swap(arr[i], arr[largest]);
	movement++;
	HeapHeapify(arr, size, largest);
}
void HeapSort(int * arr , int size) {
	
	int * temparr = new int[size];
	for (int i = 0; i < size; i++)
		temparr[i] = arr[i];

	for (int i = size / 2 - 1; i >= 0; i--) 
		HeapHeapify(temparr, size, i);
	for (int i = size - 1; i >= 0; i--) {
		swap(temparr[0], temparr[i]);
		movement++;
		HeapHeapify(temparr, i, 0);
	}
	cout << endl;
	cout << "------HeapSort result" << endl;
	cout << "Movement: " << movement << "\t" << "Comparison: " << compare << endl;

	initCount();

	delete[] temparr;
}


void RadixSort(int * arr, int size) {

	int * temparr = new int[size];
	for (int i = 0; i < size; i++)
		temparr[i] = arr[i];

	const int notation = 10;
	int i, pos = 1, *cnt, *tmp;
	int p = Getmaxdigit(temparr, size);
	tmp = new int[size*sizeof(int)];
	cnt = new int[notation * sizeof(int)];

	while (--p >= 0)
	{
		for (i = 0; i < notation; i++)
			cnt[i] = 0;             // initialize counter


		for (i = 0; i < size; i++)
			cnt[(temparr[i] / pos) % notation]++; // get number of target



		for (i = 1; i < notation; i++)
			cnt[i] += cnt[i - 1];     // get cumulative number

		for (i = size - 1; i >= 0; i--) {
			tmp[--cnt[(temparr[i] / pos) % notation]] = temparr[i];       // rearrangement
			movement++;
		}
		memcpy(temparr, tmp, size * sizeof(int));                   //copy it to original array
		pos *= notation;
	}
	cout << endl;
	cout << "------Radixsort result" << endl;
	cout << "Movement: " << movement << "\t" << "Comparison: " << 0 << endl;
	initCount();
	delete[] temparr;
}