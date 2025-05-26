// noj.am.20149.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long flag = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (flag == 0) return 0;
	else return flag > 0 ? 1 : -1;
}

void calcPoint(pair<long long, long long> a1, pair<long long, long long> a2, pair<long long, long long> b1, pair<long long, long long> b2) {
	double x1 = a1.first, y1 = a1.second;
	double x2 = a2.first, y2 = a2.second;
	double x3 = b1.first, y3 = b1.second;
	double x4 = b2.first, y4 = b2.second;

	double px = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	double py = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	double p = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);


	if (p == 0) {
		if (a2 == b1 && a1 <= b1) cout << a2.first << " " << a2.second;
		else if (a1 == b2 && b1 <= a1) cout << a1.first << " " << a1.second;
	} else {
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

void calcIntersect(pair<long long, long long> a1, pair<long long, long long> a2, pair<long long, long long> b1, pair<long long, long long> b2) {
	int ab1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
	int ab2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

	if (ab1 == 0 && ab2 == 0) {
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);
		if (a1 <= b2 && a2 >= b1) {
			cout << 1 << '\n';
			calcPoint(a1, a2, b1, b2);
		} else cout << 0 << '\n';
	} else if (ab1 <= 0 && ab2 <= 0) {
		cout << 1 << '\n';
		calcPoint(a1, a2, b1, b2);
	} else {
		cout << 0;
	}
}

int main() {
	pair<long long, long long> a1, a2, b1, b2;
	cin >> a1.first >> a1.second >> a2.first >> a2.second;
	cin >> b1.first >> b1.second >> b2.first >> b2.second;
	
	calcIntersect(a1, a2, b1, b2);
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
