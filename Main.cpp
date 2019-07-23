#include<iostream>
#include<cstdlib>
#include<chrono>
#include<cmath>
#include<list>
#include"ArrayList.h"
#include"Sorting.h"


using namespace std;
using namespace std::chrono;

#define TIME_START start = chrono::system_clock::now();		// time starts
#define TIME_END end = chrono::system_clock::now();			// time ends
#define TIME_DURATION milisec2 = duration_cast<chrono::milliseconds>(end - start);	//measuring time between sorting.
int main(void) {

	chrono::system_clock::time_point start, end;
	chrono::milliseconds milisec2;
	while (1) {
		
		int n;
		cout << "Enter the number of elements(0 to exit): ";
		cin >> n;
		if (n <= 0)
			break;

		List L1(n);
		List * ptr = &L1;

		

		// Inorder 
		cout << "\t-----Inorder------" << endl;
		TIME_START
			InsertionSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			SelectionSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			QuickSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			MergeSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			HeapSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			RadixSort(ptr->GetInorder(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		cout << endl;

		//Reverse
		cout << "\t-----Reverse-----" << endl;

		TIME_START
			InsertionSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			SelectionSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			QuickSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			MergeSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			HeapSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			RadixSort(ptr->GetReverse(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		cout << endl;

		//AlmostOrder
		cout << "\t-----AlmostOrder-----" << endl;

		TIME_START
			InsertionSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			SelectionSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			QuickSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			MergeSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			HeapSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			RadixSort(ptr->GetAlmost(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		cout << endl;

		//Random
		cout << "\t------Random------" << endl;

		TIME_START
			SelectionSort(ptr->GetRandom(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			InsertionSort(ptr->GetRandom(L1), n);
		TIME_END
		
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;
		QuickSort(ptr->GetRandom(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			MergeSort(ptr->GetRandom(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			HeapSort(ptr->GetRandom(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;

		TIME_START
			RadixSort(ptr->GetRandom(L1), n);
		TIME_END
		TIME_DURATION
			cout << "Time: " << milisec2.count() << "ms" << endl;
		
		

	}

	return 0;
}