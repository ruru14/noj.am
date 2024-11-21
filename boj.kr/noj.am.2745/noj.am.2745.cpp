// noj.am2745.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h>

int charToNumber(char c) {
	if (c >= 'A') return c - 55;
	else return c - 48;
}

int main() {
	std::string number;
	int radix, answer = 0;
	std::cin >> number >> radix;

	for (int i = 0; i < number.size(); i++) {
		answer += pow(radix, i) * charToNumber(*(number.end() - i - 1));
	}

	std::cout << answer;
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
