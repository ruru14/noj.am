// noj.am.9267.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
* 문제의 값이 unsinged long long보다 커짐
#include <numeric>

#define LL __int128
*/

using namespace std;

#define LL unsigned long long

struct x_gcd {
    LL g;
    LL x;
    LL y;
};

LL gcd(LL a, LL b) {
    LL r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

x_gcd ex_euclid(LL a, LL b) {
    if (b == 0) return { a, 1, 0 };
    x_gcd nxt = ex_euclid(b, a % b);

    return { nxt.g, nxt.y, nxt.x - (a / b) * nxt.y };
}

int main() {
    long long aa, bb, cc;
    cin >> aa >> bb >> cc;

    LL a, b, c;
    a = aa;
    b = bb;
    c = cc;

    if (c == 0) {
        if (a == 0 || b == 0) { cout << "YES"; return 0; } else { cout << "NO"; return 0; }
    }
    if (a == 0 && b == 0) { cout << "NO"; return 0; }
    if (a == 0) {
        if (c % b == 0) { cout << "YES"; return 0; } else { cout << "NO"; return 0; }
    }
    if (b == 0) {
        if (c % a == 0) { cout << "YES"; return 0; } else { cout << "NO"; return 0; }
    }
    if (a == c || b == c) { cout << "YES"; return 0; }

    auto foo = ex_euclid(a, b);
    if (c % foo.g != 0) { cout << "NO"; return 0; }

    a /= foo.g;
    b /= foo.g;
    c /= foo.g;

    LL x = foo.x * c;
    LL y = foo.y * c;

    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    LL bar = (x - 1) / b;
    y += bar * a;
    x -= b * bar;

    while (y > 0) {
        if (x > 0 && y > 0 && ex_euclid(x, y).g == 1) {
            cout << "YES";
            return 0;
        }
        x += b;
        y -= a;
    }
    cout << "NO";
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
