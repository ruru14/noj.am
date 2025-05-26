// noj.am.17386.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long flag = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (flag == 0) return 0;
	else return flag > 0 ? 1 : -1;
}

int main()
{
	pair<long long, long long> a1, a2, b1, b2;
	cin >> a1.first >> a1.second >> a2.first >> a2.second;
	cin >> b1.first >> b1.second >> b2.first >> b2.second;
	if (ccw(a1, a2, b1) * ccw(a1, a2, b2) < 0 && ccw(b1, b2, a1) * ccw(b1, b2, a2) < 0) cout << "1";
	else cout << "0";
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
