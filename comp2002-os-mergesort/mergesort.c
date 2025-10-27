/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){

}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){ //Just a regular serial mergesort algorithm 
	int middle;
	//Base case: when there's 1 element
	if (left >= right) {
		return;
	}

	//Otherwise call mergesort on the left and right half 
	middle = (left + right)/2; //should floor, making left smaller than right if odd 
	my_mergesort(left, middle);
	my_mergesort(middle+1, right);

	//Merge the two sorted sub arrays
	merge(left, middle, middle+1, right);
}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
		return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){

		return NULL;
}

