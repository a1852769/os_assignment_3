/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"
//#include "test-mergesort.c"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	int leftptr = leftstart;	//Pointer for the left sub array
	int rightptr = rightstart;	//Pointer for the right sub array
	int newptr 	= leftstart; 	//Pointer for the new array

	int leftsize = leftend - leftstart + 1;
	int rightsize = rightend - rightstart + 1;
	//printf("Elements in left half: %d\n", leftsize);
	//printf("Elements in right half: %d\n", rightsize);

	while (leftptr <= leftend && rightptr <= rightend){	//While there's at least 1 value in each half 
		//printf("left element:%d, right element:%d\n", A[leftptr],A[rightptr]);
		if(A[leftptr]<=A[rightptr]){
			//printf("left is smaller, placing into B\n");
			B[newptr] = A[leftptr];
			leftptr++;
		} else {
			//printf("right is smaller, placing into B\n");
			B[newptr] = A[rightptr];
			rightptr++;
		}
		newptr++;
	}

	//once one half has run out of elements 
	while (leftptr <= leftend){
		//printf("placing rest of left elements\n");
		B[newptr] = A[leftptr];
		newptr++;
		leftptr++; 
	}

	while (rightptr <= rightend){
		//printf("placing rest of right elements\n");
		B[newptr] = A[rightptr];
		newptr++;
		rightptr++; 
	}
	//printB();
	//Copy the temporary array back into A: memcpy(*to, *from, numBytes)
	//printf("Copying to A...\n");
	memcpy(A + leftstart, B + leftstart,sizeof(int)*(rightend - leftstart +1));
	//printA();
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){ //Just a regular serial mergesort algorithm 
	int middle;
	//Base case: when there's 1 element
	if (left >= right) {
		//printf("base case reached\n");
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
	//extract the arguments from the struct 
	struct argument *args = (struct argument *) arg;
	int left = args->left;
	int right = args->right;
	int level = args->level;

	//Testing if arguments have been passed correctly.
	printf("left: %d\n", left);
	printf("right: %d\n", right);
	printf("level: %d\n", level);
	

		return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	//Make a new argument struct 
	struct argument *args = malloc(sizeof(struct argument));
		if (args == NULL){
			perror("argument could not build");
			exit(1);
		}

	//Assign the arguments to the struct
	args->left = left;
	args->right = right; 
	args->level = level;
		return args;
}

