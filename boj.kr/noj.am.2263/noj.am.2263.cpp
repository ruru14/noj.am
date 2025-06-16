// noj.am.2263.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define MAX 100'001

using namespace std;

int n;
int in[MAX], post[MAX], idx[MAX];

void toPre(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd) return;
	int root = post[postEnd];
	cout << root << " ";

	int mid = idx[root];
	int inLeftStart = inStart, inLeftEnd = mid - 1;
	int inRightStart = mid + 1, inRightEnd = inEnd;

	int postLeftStart = postStart, postLeftEnd = (mid - inStart) + postStart - 1;
	int postRightStart = (mid - inStart) + postStart, postRightEnd = postEnd - 1;

	toPre(inLeftStart, inLeftEnd, postLeftStart, postLeftEnd);
	toPre(inRightStart, inRightEnd, postRightStart, postRightEnd);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> post[i];

	toPre(0, n - 1, 0, n - 1);
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
