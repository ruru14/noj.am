// noj.am.14916.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int n, answer = 0;
	cin >> n;

	if (n == 1 || n == 3) { 
		cout << -1; 
		return 0; 
	}

	answer += n / 5;
	n %= 5;
	if (n % 5 == 0) { 
		cout << answer; 
		return 0; 
	}
	else {
		if (n == 1 || n == 3) {
			n += 5;
			answer--;
		}
		answer += n / 2;
	}
	cout << answer;
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
