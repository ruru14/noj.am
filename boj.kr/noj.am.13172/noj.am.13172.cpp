// noj.am.13172.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ll long long
#define MOD 1'000'000'007

struct x_gcd {
    ll g;
    ll x;
    ll y;
};

x_gcd ex_euclid(ll a, ll b) {
    if (b == 0) return { a,1,0 };
    x_gcd nxt = ex_euclid(b, a % b);

    return { nxt.g, nxt.y, nxt.x - (a / b) * nxt.y };
}

ll mod_inverse(ll a, ll mod) {
    auto res = ex_euclid(a, mod);
    if (res.g > 1) return -1;
    return (res.x + mod) % mod;
}

int main()
{
    int m;
    ll ans = 0, n, s;
    cin >> m;
    
    while (m--) {
        cin >> n >> s;
        ans += ((s % MOD) * (mod_inverse(n, MOD) % MOD) % MOD);
        ans %= MOD;
    }
    
    cout << ans;
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
