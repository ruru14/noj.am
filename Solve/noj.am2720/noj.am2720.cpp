// noj.am2720.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int tc, money;
	std::cin >> tc;

	for (; tc > 0; tc--) {
		std::cin >> money;
		std::cout << money / 25 << " ";
		money = money % 25;
		std::cout << money / 10 << " ";
		money = money % 10;
		std::cout << money / 5 << " ";
		money = money % 5;
		std::cout << money << "\n";
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
