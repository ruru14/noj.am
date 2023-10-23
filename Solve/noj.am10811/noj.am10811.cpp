// noj.am10811.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
	int n, m;
	int i, j;
	std::cin >> n >> m;
	std::vector<int> bucket;
	for (int cnt = 0; cnt <= n; cnt++) {
		bucket.push_back(cnt);
	}
	// bucket[i] = i

	for (int cnt = 0; cnt < m; cnt++) {
		std::vector<int> tmp;
		std::cin >> i >> j;
		for (int idx = 0; idx < i; idx++) {
			tmp.push_back(bucket[idx]);
		}
		for (int idx = j; idx >= i; idx--) {
			tmp.push_back(bucket[idx]);
		}
		for (int idx = j + 1; idx <= n; idx++) {
			tmp.push_back(bucket[idx]);
		}
		bucket = tmp;
	}

	bucket.erase(bucket.begin());

	for (auto& i : bucket) {
		std::cout << i << " ";
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
