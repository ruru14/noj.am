// noj.am.16900.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string ptn) {
	vector<int> pi(ptn.size(), 0);
	int j = 0;
	for (int i = 1; i < ptn.size(); i++) {
		while (j > 0 && ptn[i] != ptn[j])
			j = pi[j - 1];
		if (ptn[i] == ptn[j])
			pi[i] = ++j;
	}
	return pi;
}

int main()
{
	string foo;
	long k, answer = 0;
	cin >> foo >> k;

	answer += foo.size();
	vector<int> pi = getPi(foo);
	answer += (foo.size() - pi[pi.size() - 1]) * (k - 1);
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
