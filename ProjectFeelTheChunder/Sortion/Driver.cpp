#include "selectsort.h"
#include <iostream>
using namespace std;

int main(){
	AwesomeVector<int>TMPE;
	int tmp = 0;
	do{
		cin >> tmp;
		TMPE.push_back(tmp);
	}while(tmp != -1);
	
	TMPE.print();
	select_sort(TMPE);
	TMPE.print();
	
	
	
	
	return 0;
}