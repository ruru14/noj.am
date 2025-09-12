// noj.am.1874.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, cur = 1;
	stack<int> st;
	vector<char> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int foo;
		cin >> foo;
		while (cur <= foo) {
			st.push(cur++);
			ans.push_back('+');
		}
		if (!st.empty()) {
			if (st.top() == foo) {
				st.pop();
				ans.push_back('-');
			} else {
				break;
			}
		}
	}
	if (ans.size() == n * 2) {
		for (auto& i : ans) cout << i << "\n";
	} else cout << "NO";
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
