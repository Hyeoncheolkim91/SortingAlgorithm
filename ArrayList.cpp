#include <iostream>
#include "ArrayList.h"

using namespace std;

void List:: ShowElement(List * plist)					//showing list elements
{
	cout << "------Original Arrays before sorting------" << endl;

	for (int i = 0; i < plist->Getsize(); i++) {
		cout << *(plist->Inorder + i) << " ";
	}

	cout << endl;
	for (int i = 0; i < plist->Getsize(); i++) {
		cout << *(plist->ReverseOrder + i) << " ";

	}
	cout << endl;

	for (int i = 0; i < plist->Getsize(); i++) {
		cout << *(plist->AlmostOrder + i) << " ";
	}

	cout << endl;

	for (int i = 0; i < plist->Getsize(); i++) {
		cout << *(plist->RandomOrder+i)  << " ";
	}

	cout << endl;


}
 int * List::GetRandom(List list) {

	return  list.RandomOrder;
	
	
}
 int * List::GetInorder(List list) {

	 return list.Inorder;
	

}
 int * List::GetReverse(List list) {
	
	 return list.ReverseOrder;
}
int * List::GetAlmost(List list) {

	return list.AlmostOrder;

}