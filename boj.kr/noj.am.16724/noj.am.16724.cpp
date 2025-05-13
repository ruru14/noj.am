// noj.am.16724.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void trable(int y, int x, const vector<string>& field, vector<vector<int>>& state, int& zone) {
    state[y][x] = 1;
    
    int ny = y, nx = x;
    switch (field[y][x]) {
    case 'U':
        ny--;
        break;
    case 'D':
        ny++;
        break;
    case 'L':
        nx--;
        break;
    case 'R':
        nx++;
        break;
    }

    if (state[ny][nx] == 0) trable(ny, nx, field, state, zone);
    else if (state[ny][nx] == 1) {
        zone++;
    }

    state[y][x] = 2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> field(n);
    vector<vector<int>> state(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) cin >> field[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (state[i][j] == 0) trable(i, j, field, state, ans);
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
