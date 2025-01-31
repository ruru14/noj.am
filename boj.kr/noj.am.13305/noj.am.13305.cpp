// noj.am.13305.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n;
	cin >> n;
	vector<long long> node(n - 1), edge(n - 1);


	for (int i = 0; i < n - 1; i++) cin >> edge[i];
	for (int i = 0; i < n - 1; i++) cin >> node[i];

	long long cost = node[0] * edge[0], tmp = 0, cheapNode = node[0];
	for (int i = 1; i < n - 1; i++) {
		if (cheapNode > node[i]) cheapNode = node[i];
		cost += cheapNode * edge[i];
	}

	cout << cost;
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
