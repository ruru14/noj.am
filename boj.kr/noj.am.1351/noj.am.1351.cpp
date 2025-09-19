// noj.am.1351.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using ll = long long;

using namespace std;

ll n, p, q;
map<ll, ll> mem;

ll func(ll val) {
    if (val == 0) return mem[val] = 1;
    if (mem[val] != 0) return mem[val];
    return mem[val] = func(val / p) + func(val / q);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p >> q;

    cout << func(n);
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
