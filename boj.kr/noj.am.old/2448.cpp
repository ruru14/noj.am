#include "2448.h"

char stars[3][5] = {
	{' ',' ','*',' ',' '},
	{' ','*',' ','*',' '},
	{'*','*','*','*','*'}
};

void nojam2448::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - (3 * ((i / 3) + 1)); k++) {
			printf(" ");
		}
		for (int l = 0; l < i / 3 + 1; l++) {
			for (int j = 0; j < 5; j++) {
				printf("%c", stars[i % 3][j]);
			}
			if (i / 3 + 1 != 0)
				printf(" ");
		}
		printf("\n");
	}
	//std::cout << stars;
	/*3                 1
	  6               1   1
	  9	            1   0   1
	  12          1   1   1   1
	  15        1   0   0   0   1
	  18	  1   1   0   0   1   1
	  21	1   0   1   0   1   0   1
	  24  1	  1   1   1   1   1   1   1

	*/
}
