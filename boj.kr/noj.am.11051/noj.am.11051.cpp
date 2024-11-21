// noj.am11051.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// (A*B)%C = (A%C * B%C) % C

int MOD = 10'007;

int cache[1001][1001];

int bino_coef(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cache[i][j] = (cache[i - 1][j] % MOD + cache[i - 1][j - 1] % MOD) % MOD;
        }
    }
    return cache[n][k];
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        cache[i][0] = 1;
        cache[i][i] = 1;
    }
    int n, k;
    cin >> n >> k;
    cout << bino_coef(n, k);
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
