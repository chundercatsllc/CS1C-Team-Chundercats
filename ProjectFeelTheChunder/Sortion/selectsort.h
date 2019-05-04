#ifndef __SELECTSORT_H__
#define __SELECTSORT_H__
#include "../containers/AwesomeVector.h"
using namespace std;

template <class T>
void swap (T *first, T *second)
{
  T tmp = *first;
  *first = *second;
  *second = tmp;
}

template <class T>
void select_sort(AwesomeVector<T> numbers){
	int i, w;
	for(i=0; i<numbers.sizeOf()-1; i++){
		int tmp_low = i;
		for(w=i+1; w<numbers.sizeOf(); w++){
			if(numbers[w] < numbers[tmp_low]){
				tmp_low = w;
			}
		}
		if(tmp_low != i){
			swap(&numbers[i], &numbers[tmp_low]);
		}
	}
}

#endif