// noj.am.1937.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
vector<vector<int>> dp, forest;

int func(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nxtR = r + dr[i];
        int nxtC = c + dc[i];
        if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= n) continue;
        if (forest[r][c] >= forest[nxtR][nxtC]) continue;
        dp[r][c] = max(dp[r][c], func(nxtR, nxtC) + 1);
    }
    return dp[r][c];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    cin >> n;
    forest.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int foo = func(i, j);
            if (foo > ans) ans = foo;
        }
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
