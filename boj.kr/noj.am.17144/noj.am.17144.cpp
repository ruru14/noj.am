// noj.am.17144.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int c_dc[] = { 1, 0, -1, 0 };
int c_dr[] = { 0, 1, 0, -1 };
int uc_dc[] = { 1, 0, -1, 0 };
int uc_dr[] = { 0, -1, 0, 1 };

int row, col, t;
vector<vector<int>> map;

bool isValid(int r, int c) {
    if (r < 0 || r >= row) return false;
    if (c < 0 || c >= col) return false;
    return true;
}

vector<vector<int>> diffusion() {
    vector<vector<int>> tmp(row, vector<int>(col, 0));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (map[r][c] > 0) {
                int diff = 0;
                for (int i = 0; i < 4; i++) {
                    int nxtC = c + c_dc[i];
                    int nxtR = r + c_dr[i];
                    if (!isValid(nxtR, nxtC) || map[nxtR][nxtC] == -1) continue;
                    diff += (map[r][c] / 5);
                    tmp[nxtR][nxtC] += map[r][c] / 5;
                }
                map[r][c] -= diff;
            }
        }
    }

    return tmp;
}

void purify(vector<vector<int>>& m, int start_r, int start_c, int dir_r[4], int dir_c[4]) {
    int clock_r = start_r, clock_c = start_c;
    int dust = 0, dir = 0;

    while (m[clock_r][clock_c] != -1) {
        int tmp = m[clock_r][clock_c];
        m[clock_r][clock_c] = dust;
        dust = tmp;

        int nxtR = clock_r + dir_r[dir];
        int nxtC = clock_c + dir_c[dir];
        if (!isValid(nxtR, nxtC)) dir++;
        clock_r += dir_r[dir];
        clock_c += dir_c[dir];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> row >> col >> t;
    map.assign(row, vector<int>(col, 0));
    vector<pair<int, int>> condi;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> map[r][c];
            if (map[r][c] == -1) {
                condi.push_back(make_pair(r, c));
            }
        }
    }

    while (t--) {
        vector<vector<int>> tmp = diffusion();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                map[r][c] += tmp[r][c];
            }
        }

        purify(map, condi[1].first, condi[1].second + 1, c_dr, c_dc);
        purify(map, condi[0].first, condi[0].second + 1, uc_dr, uc_dc);
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (map[r][c] > 0) ans += map[r][c];
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
