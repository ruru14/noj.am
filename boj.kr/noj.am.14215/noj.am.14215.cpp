// noj.am14215.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int a, b, c;
	std::vector<int> arr;
	std::cin >> a >> b >> c;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	std::sort(arr.begin(), arr.end());
	a = *arr.begin();
	b = *(arr.begin() + 1);
	c = *(arr.begin() + 2);

	while (a + b <= c) {
		c--;
	}
	std::cout << a + b + c;
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
