//============================================================================
// Name        : 20210928_TASK09_Bubblesort.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& rPara_1, int& rPara_2)// use reference to swap two integers
{
	int iMiddle;
	iMiddle = rPara_1;
	rPara_1 = rPara_2;
	rPara_2 = iMiddle;
}

void Bubblesort(int* iRef, int n)
{
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1;j++){	 //get the (i+1)th biggest number
			if(iRef[j]>iRef[j+1]){
				swap(iRef[j],iRef[j+1]);
			}
		}
	}
}

int main() {
	srand(time(nullptr));
	int i=0;
	int* piArray = new int[32]; //declare an int-array in the heap

	/* print the original array*/
	cout << "Original array: " << endl;
	for(i=0; i<32; i++){
		piArray[i] = rand()%100;
		cout << piArray[i] << " ";
	}

	/* print the sorted array*/
	cout << endl;
	Bubblesort(piArray, 32);
	cout << "Sorted array: " << endl;
	for(i=0; i<32; i++){
		cout << piArray[i] << " ";
		}

	return 0;
}
