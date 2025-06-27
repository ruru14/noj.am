// noj.am.2565.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());

	vector<int> tails;

	for (int i = 0; i < arr.size(); i++) {
		auto it = lower_bound(tails.begin(), tails.end(), arr[i].second);
		if (it == tails.end()) tails.push_back(arr[i].second);
		else *it = arr[i].second;
	}

	cout << n - tails.size();
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
