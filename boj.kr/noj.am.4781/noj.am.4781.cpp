// noj.am4781.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int c[5001]; // calorie
int p[5001]; // price
int dp[10001];

int main() {
    int n, m;
    float tmp = -1.f;
    cin >> n >> tmp;

    while (tmp != 0.00) {
        fill_n(c, 5001, 0);
        fill_n(p, 5001, 0);
        fill_n(dp, 10001, 0);
        m = (int)(tmp * 100);

        for (int i = 1; i <= n; i++) {
            int foo;
            float bar;
            cin >> foo >> bar;
            c[i] = foo;
            p[i] = bar * 100;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = p[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
            }
        }

        cout << dp[m] << "\n";
        cin >> n >> tmp;
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
