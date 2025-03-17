// noj.am.12015.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, ans;

int bSearch(int val) {
	int low = 0, high = ans.size() - 1, mid;

	while (low < high) {
		mid = (low + high) / 2;
		if (ans[mid] >= val) high = mid;
		else low = mid + 1;
	}

	return high;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];
	ans.push_back(arr.front());

	for (int i = 1; i < n; i++) {
		if (arr[i] > ans.back()) ans.push_back(arr[i]);
		else {
			ans[bSearch(arr[i])] = arr[i];
		}
	}

	cout << ans.size();
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
