// noj.am.2166.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

long long crossProduct(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first * b.second - a.second * b.first);
}

int main()
{
    int n;
    long long ans = 0.0;
    cin >> n;
    pair<long long, long long> a, b;
    cin >> a.first >> a.second;
    b = a;
    
    for (int i = 0; i < n - 1; i++) {
        long long foo, bar;
        cin >> foo >> bar;
        ans += crossProduct(b, { foo,bar });
        b = { foo,bar };
    }
    ans += crossProduct(b, a);

    cout << fixed;
    cout.precision(1);
    cout << abs(ans) / 2.0;
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
