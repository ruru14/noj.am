// noj.am.2467.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 2'000'000'001

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int start = 0, end = n - 1, sum = INF;
	int ansS = 0, ansE = n - 1;
	vector<int> liq(n, 0);

	for (int i = 0; i < n; i++) cin >> liq[i];

	while (start < end) {
		int gab = liq[start] + liq[end];
		if (abs(gab) < sum) {
			sum = abs(gab);
			ansS = start;
			ansE = end;
		}
		if (gab < 0) start++;
		else end--;
	}

	cout << liq[ansS] << " " << liq[ansE];
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
