// noj.am.2812.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string foo;
	cin >> foo;
	
	deque<char> bar;
	int tmp = k;
	for (int i = 0; i < n; i++) {
		while ((!bar.empty() && bar.back() < foo[i]) && tmp > 0) {
			bar.pop_back();
			tmp--;
		}
		bar.push_back(foo[i]);
	}

	while (tmp > 0) {
		bar.pop_back();
		tmp--;
	}

	while (!bar.empty()) {
		cout << bar.front();
		bar.pop_front();
	}
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
