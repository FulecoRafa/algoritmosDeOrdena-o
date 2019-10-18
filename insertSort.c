#include <stdio.h>

void insertion_sort(int *a , int max){
 int i, j, tmp;
  
 for(i = 1; i < max; i++){
  	tmp = a[i];
	for(j = i-1; j >= 0 && tmp < a[j]; j--){
  		a[j+1] = a[j];
  	}
 	a[j+1] = tmp;
 }
}
