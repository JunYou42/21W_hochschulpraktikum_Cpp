//============================================================================
// Name        : 20210928_TASK08_Speicher_und_Arrays.cpp
// Author      : Stone
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(nullptr));
	int k=0;
	int i=0;
	int* piDynamic = new int[100000];
	for(i=0; i<100000; i++){
		piDynamic[i] = rand()%100;
		if(piDynamic[i] % 13 == 0){
			k++;
		}
	}
	cout << "There are " << k << " numbers in the array that can be divided exactly by 13." ;

	delete[] piDynamic;

	return 0;
}
