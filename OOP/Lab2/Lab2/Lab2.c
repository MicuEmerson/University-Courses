// Lab2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"

typedef struct {

	int vec[10000];
	int n;

}vector ;

vector generate(int n)
{
	/***
	Function:
	- in this function we generate all prime numbers smaller then a given 'n'
	- we do an eratostene sieve
	- after we print all the indices from our vector who have value 1 on that index
	- O(n) time complexity

	Params:
	n = the given number

	Variables and Vectors:
	v[] = vector used for eratostene sieve
	i and j = indices for loops
	***/

	vector v;
	v.n = n;
	int i, j;

	for (i = 2; i <= n; i++)
		v.vec[i] = 1;

	for (i = 2; i <= n; i++)
		if (v.vec[i] == 1)
			for (j = i + i; j <= n; j += i)
				v.vec[j] = 0;

	return v;
	
}

void longest(vector v, int *start, int *maxy)
{
	/***
	Function:
	- in this function we find the longest increasing contiguous subsequence
	- after we print the longest increasing contiguous subsequence from vector v[]
	- O(n) time complexity, because if two contiguous elements do not qualify then we can start
	trying from the points to make another L.I.C.S, because if we start from 'start+1' we find a good solution
	but that solution will be always lower then our previous result so we our L.I.C.S won't change.

	Params:
	v[] = the initial vector
	n = the vector 'v[]' size
	Variables and Vectors:

	maxy = variable to keep maximum length of L.I.C.S
	start = varibale to keep the starting index of L.I.C.S
	i and j = indices for loops

	***/
	int i;
	
	for (i = 0; i < v.n; i++)
	{
		int j = i;
		if (v.vec[j] < v.vec[j + 1] && j + 1 < v.n)
		{
			while (v.vec[j] < v.vec[j + 1] && j + 1 < v.n)
					j++;

			if (j - i > *maxy)
			{
				*maxy = j - i;
				*start = i;
			}
			i = --j;
		}
	}
	
	
}


vector read() {
    /**
	  Simple function to read a vector
	  Return a vector with 'vector' structure
	**/
	vector x;
	printf("vector size: ");
	scanf_s("%d", &x.n);
	printf("\n numbers: ");

	int i;
	for (i = 0; i < x.n; i++)
		scanf_s("%d", &x.vec[i]);
	
	return x;

}


int gcd(int x, int y) {

	int r = x % y;
	while (r)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y;

}

void addition(int n) {

	int i;
	for (i = 1; i < n; i++)
		if (gcd(i, n) == 1)
			printf("%d ", i);

	printf("\n");
}


int main()
{  
	
	
	
	while (1)
	{
		int q, n;
		printf("1. Generate all the prime numbers smaller than a given natural number n\n");
		printf("2. Given a vector of numbers, find the longest increasing contiguous subsequence\n");
		printf("3. Addition\n");
		printf("0. Exit\n");
		scanf_s("%d", &q);
		if (q == 1)
		{
			printf("number: ");
			scanf_s("%d", &n);
			vector v = generate(n);
			int i;
			for (i = 2; i < n; i++)
				if (v.vec[i] == 1)
					printf("%d ", i);

			printf("\n");
			
		}
		else if (q == 2)
		{
			vector v = read();
			int maxy = 0;
			int start = 0;
			int i;

			longest(v, &start, &maxy);
			
			for (i = start; i <= start + maxy; i++)
				printf("%d ", v.vec[i]);

			printf("\n");
		}
		else if (q == 3) {

			printf("number: ");
			scanf_s("%d", &n);
			addition(n);

		}
		else if (q == 0)
		{
			break;
		}
		else
		{
			printf("Invalid input\n");
		}
	}
	return 0;
}
