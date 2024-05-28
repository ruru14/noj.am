#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int idx = 0;
int n, r = 0, c = 0;

void foo(int sX, int eX, int sY, int eY, int tX, int tY) {
	int size = eX - sX + 1;

	if ((sY + eY) / 2 >= tY) {
		if ((sX + eX) / 2 >= tX) {
			// 1Q
			n--;
			if(size > 1) foo(sX, (sX + eX) / 2, sY, (sY + eY) / 2, tX, tY);
		} else {
			// Right
			// 2Q
			idx += pow(4, (n--) - 1) * 1;
			if (size > 1) foo((sX + eX) / 2 + 1, eX, sY, (sY + eY) / 2, tX, tY);

		}
	} else {
		if ((sX + eX) / 2 >= tX) {
			// 3Q
			idx += pow(4, (n--) - 1) * 2;
			if (size > 1) foo(sX, (sX + eX) / 2, (sY + eY) / 2 + 1, eY, tX, tY);
		} else {
			// 4Q
			idx += pow(4, (n--) - 1) * 3;
			if (size > 1) foo((sX + eX) / 2 + 1, eX, (sY + eY) / 2 + 1, eY, tX, tY);

		}
	}
}

int main()
{
	int size = 0;
	cin >> n >> r >> c;
	size = pow(2, n);

	foo(0, size - 1, 0, size - 1, c, r);
	cout << idx;
}