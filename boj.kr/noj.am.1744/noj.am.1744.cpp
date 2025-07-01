// noj.am.1744.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0, zero = 0;
	cin >> n;
	vector<int> minus, plus;

	for (int i = 0; i < n; i++) {
		int foo;
		cin >> foo;
		if (foo == 0) zero++;
		else if (foo == 1) ans++;
		else if (foo > 0) plus.push_back(foo);
		else minus.push_back(foo);
	}

	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	int plusLen = plus.size();
	for (int i = 0; i < plusLen; i++) {
		if (i < plusLen - 1) {
			ans += plus[i] * plus[i + 1];
			i += 1;
		} else {
			ans += plus[i];
		}
	}

	int minusLen = minus.size();
	for (int i = 0; i < minusLen; i++) {
		if (i < minusLen - 1) {
			ans += minus[i] * minus[i + 1];
			i += 1;
		} else {
			if (zero == 0) ans += minus[i];
		}
	}

	cout << ans;
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
