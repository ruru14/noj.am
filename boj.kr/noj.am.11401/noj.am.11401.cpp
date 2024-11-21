// noj.am11401.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int MOD = 1'000'000'007;

long long power(int a, int b) {
    if (b == 1) return a % MOD;
    long long half = power(a, b / 2);
    if (b % 2 == 1) {
        return half * half % MOD * a % MOD;
    } else {
        return half * half % MOD;
    }
}

long long factorial(long long a, long long b) {
    long long ans = 1;
    for (int i = a; i <= b; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << factorial(n - k + 1, n) * power(factorial(1, k), MOD - 2) % MOD;
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
