// noj.am.14565.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define LL long long

struct x_gcd {
    LL g;
    LL x;
    LL y;
};

x_gcd ex_euclid(LL a, LL b) {
    if (b == 0) return { a, 1, 0 };
    x_gcd nxt = ex_euclid(b, a % b);

    return { nxt.g, nxt.y, nxt.x - (a / b) * nxt.y };
}

int main()
{
    LL n, a;
    cin >> n >> a;
    auto foo = ex_euclid(n, a);

    cout << n - a << " ";
    if (foo.g != 1) cout << -1;
    else {
        if (foo.y < 0) cout << n + foo.y;
        else cout << foo.y;
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
