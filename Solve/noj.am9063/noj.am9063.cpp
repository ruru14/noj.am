// noj.am9063.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> hor, ver;
	std::cin >> n;
	
	for (; n > 0; n--) {
		int a, b;
		std::cin >> a >> b;
		hor.push_back(a);
		ver.push_back(b);
	}
	std::sort(hor.begin(), hor.end());
	std::sort(ver.begin(), ver.end());

	std::cout << (*(hor.end() - 1) - *(hor.begin())) * (*(ver.end() - 1) - *(ver.begin()));
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
