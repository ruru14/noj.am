#include "13015.h"

void nojam13015::solution()
{
	int n;
	scanf("%d", &n);
	// 2 : 0 1 2
	// 1 0 1
	
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int a = (int)abs(i - n + 1); a < n - 1; a++) {
			printf(" ");
		}
		if (i == 0 | i == (2 * n - 2)) { //Top, Bottom
			for (int a = 0; a < n; a++) {
				printf("*");
			}
			for (int a = 0; a < 2 * n - 3; a++) {
				printf(" ");
			}
			for (int a = 0; a < n; a++) {
				printf("*");
			}
			printf("\n");
		}
		else if (i == (n - 1)) { // Mid
			printf("*");
			for (int a = 0; a < n - 2; a++) {
				printf(" ");
			}
			printf("*");
			for (int a = 0; a < n - 2; a++) {
				printf(" ");
			}
			printf("*\n");
		}
		else {
			printf("*");
			for (int a = 0; a < n - 2; a++) {
				printf(" ");
			}
			printf("*");
			for (int a = 0; a < (int)abs(i - n + 1) * 2 - 1; a++) {
				printf(" ");
			}
			printf("*");
			for (int a = 0; a < n - 2; a++) {
				printf(" ");
			}
			printf("*\n");
		}
		// 0 1 2 3 4 5 6 7 8
		// 0 3 2 1 0 1 2 3
		// 0 5 4 3 0 3 4 5 0
		// 4 3 2 1 0 1 2 3 4
		// 0 1 2 3 4 3 2 1 0
		// 2 : 3
		// 3 : 5
		// 4 : 7
		// 5 : 9
		/*
		* 2n-3
		* 2 : 1
		 ooo   ooo 3 : 3
		  o o o o
		   o o o
		  o o o o
		 ooo   ooo

		 oooo     oooo 4 : 5
		  o  o   o  o
		   o  o o  o
			o  o  o
		   o  o o  o
		  o  o   o  o
		 oooo     oooo
		 5 : 7
		*/
	}
}
