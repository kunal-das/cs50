/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

int binarySearch(int A[], int l, int r, int x);
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
	int index = binarySearch(values, 0, n-1, value);
		
	if(index != -1)
		return true;
	else
		return false;
	
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm. Implementing INSERION SORT.
	int j;
	int temp;
	for(int i = 1; i < n; i++)
	{
	 	j=i;
	 	while(j > 0 && values[j-1] > values[j])
	 	{
	 		temp = values[j-1];
	 		values[j-1] = values[j];
	 		values[j] = temp;
	 		j--;
	 	}
	} 
}

int binarySearch(int A[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r-1)/2;

		//If x lies in the middle of the sorted array.
		if(A[mid] == x)
			return mid;
		//If x lies in the right side of the sorted array.
		if(x > A[mid])
			return binarySearch(A, mid+1, r, x);
		//If x lies in the left side of the sorted array.
		return binarySearch(A, l, mid-1, x);
	}
	return -1;
}
