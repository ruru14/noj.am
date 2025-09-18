// noj.am.11723.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int m;
	int s = 0;
	cin >> m;
	while (m--) {
		string foo;
		int bar;
		cin >> foo;
		
		if (foo == "add") {
			cin >> bar;
			s |= (1 << (bar - 1));
		} else if (foo == "remove") {
			cin >> bar;
			s &= (~(1 << (bar - 1)));
		} else if (foo == "check") {
			cin >> bar;
			cout << ((s >> (bar - 1)) & 1) << "\n";
		} else if (foo == "toggle") {
			cin >> bar;
			s ^= (1 << (bar - 1));
		} else if (foo == "all") {
			s = 0xfffff;
		} else {
			s = 0;
		}
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
