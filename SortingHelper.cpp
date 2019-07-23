#include"SortingHelper.h"
#include<iostream>
using namespace std;

void swap(int *n1, int *n2) {

	int temp;
									//swap two number
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int Getmaxdigit(int * arr, int n)
{									
	int max = arr[0];
	int exp=1;
	int j = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)					// find max number
			max = arr[i];
	}
	
	while (1) {					// quotient is the maxdigit
		if (max / exp < 10) 
			break;				
									
		exp = exp *10;
		j++;
		
	}
	

	return j;			// return maxdigit.
}


void showArray(int * arr,int n) {				//printing array 

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}