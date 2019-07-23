#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include<ctime>





class List {				//class List.
private:

	int * Inorder;
	int * ReverseOrder;
	int * AlmostOrder;
	int * RandomOrder;
	int size;


public:
	List(int n) {				//constructor for List
		
		Inorder = new int[n];					//initialize inorder array
		for (int i = 0; i < n; i++) {			
			Inorder[i] = i;
		}
		
		ReverseOrder = new int[n];		//initialize reverse order
		for (int i = n - 1; i >= 0; i--) {
			
				ReverseOrder[i] = n-i-1;
			
		}
		
		AlmostOrder = new int[n];			//initialize Almost order. 
		for (int i = 0; i < n; i++) {
			AlmostOrder[i] = i;
		}
		int temp = AlmostOrder[n - 1];
		AlmostOrder[n - 1] = AlmostOrder[0];			//swap last and first element
		AlmostOrder[0] = temp;
		
		
		
		RandomOrder = new int[n];			//initialize random order
		int pos;
		int temp2;
		srand((unsigned)time(NULL));

		for (int i = 0; i < n; i++) {


			RandomOrder[i] = i;				
		}
		for (int i = 0; i < n; i++) {
			pos = rand() % n;					//generate random numbers without repetition
			temp2 = RandomOrder[i];
			RandomOrder[i] = RandomOrder[pos];
			RandomOrder[pos] = temp2;

		}
		size = n;
	}
	void static ShowElement(List * plist);
	
	int Getsize() {				// get size of list
		return size;
	}
	 
	int * GetRandom(List list);
	 int * GetInorder(List list);
	 int * GetReverse(List list);
	 int * GetAlmost(List list);
	 
	 ~List() {

	 }

};




#endif