// noj.am.15683.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m, ans = 65, cnt;
vector<pair<int, int>> cctv;

void track(vector<vector<int>> tv, int cur) {
    if (cur == cnt) {
        int cnt = 0;
        for (auto& i : tv) {
            for (auto& j : i) {
                if (j == 0) cnt++;
            }
        }

        ans = min(ans, cnt);
        return;
    }

    switch (tv[cctv[cur].first][cctv[cur].second]) {
    case 1:
    {
        int dr[] = { 1,0,-1,0 };
        int dc[] = { 0,1,0,-1 };
        for (int i = 0; i < 4; i++) {
            int nxtR = cctv[cur].first;
            int nxtC = cctv[cur].second;
            vector<vector<int>> nxt(tv);
            while (1) {
                nxtR = nxtR + dr[i];
                nxtC = nxtC + dc[i];
                if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) break;
                if (nxt[nxtR][nxtC] == 6) break;
                if (nxt[nxtR][nxtC] == 0) nxt[nxtR][nxtC] = 7;
            }
            track(nxt, cur + 1);
        }
    }
        break;
    case 2:
    {
        int dr[2][2] = { {1,-1} ,{0,0} };
        int dc[2][2] = { {0,0} ,{1,-1} };
        for (int i = 0; i < 2; i++) {
            vector<vector<int>> nxt(tv);
            for (int j = 0; j < 2; j++) {
                int nxtR = cctv[cur].first;
                int nxtC = cctv[cur].second;
                while (1) {
                    nxtR = nxtR + dr[i][j];
                    nxtC = nxtC + dc[i][j];
                    if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) break;
                    if (nxt[nxtR][nxtC] == 6) break;
                    if (nxt[nxtR][nxtC] == 0) nxt[nxtR][nxtC] = 7;
                }
            }
            track(nxt, cur + 1);
        }
    }
        break;
    case 3:
    {
        int dr[4][2] = { {1, 0}, {1, 0}, {-1, 0}, {-1, 0} };
        int dc[4][2] = { {0, -1}, {0, 1}, {0, 1}, {0, -1} };
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> nxt(tv);
            for (int j = 0; j < 2; j++) {
                int nxtR = cctv[cur].first;
                int nxtC = cctv[cur].second;
                while (1) {
                    nxtR = nxtR + dr[i][j];
                    nxtC = nxtC + dc[i][j];
                    if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) break;
                    if (nxt[nxtR][nxtC] == 6) break;
                    if (nxt[nxtR][nxtC] == 0) nxt[nxtR][nxtC] = 7;
                }
            }
            track(nxt, cur + 1);
        }
    }
        break;
    case 4:
    {
        int dr[4][3] = { {0, 1, -1},{0, 1, 0},{1, 0, -1},{0, 0, -1} };
        int dc[4][3] = { {-1, 0, 0}, {-1, 0, 1}, {0, 1, 0}, {-1, 1, 0} };
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> nxt(tv);
            for (int j = 0; j < 3; j++) {
                int nxtR = cctv[cur].first;
                int nxtC = cctv[cur].second;
                while (1) {
                    nxtR = nxtR + dr[i][j];
                    nxtC = nxtC + dc[i][j];
                    if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) break;
                    if (nxt[nxtR][nxtC] == 6) break;
                    if (nxt[nxtR][nxtC] == 0) nxt[nxtR][nxtC] = 7;
                }
            }
            track(nxt, cur + 1);
        }
    }
        break;
    case 5:
    {
        int dr[] = { 1,0,-1,0 };
        int dc[] = { 0,1,0,-1 };
        vector<vector<int>> nxt(tv);
        for (int i = 0; i < 4; i++) {
            int nxtR = cctv[cur].first;
            int nxtC = cctv[cur].second;
            while (1) {
                nxtR = nxtR + dr[i];
                nxtC = nxtC + dc[i];
                if (nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) break;
                if (nxt[nxtR][nxtC] == 6) break;
                if (nxt[nxtR][nxtC] == 0) nxt[nxtR][nxtC] = 7;
            }
        }
        track(nxt, cur + 1);
    }
        break;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            if (field[i][j] > 0 && field[i][j] < 6) {
                cctv.push_back({ i,j });
                cnt++;
            }
        }
    }
    track(field, 0);

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
