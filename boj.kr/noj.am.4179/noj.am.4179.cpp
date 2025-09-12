// noj.am.4179.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

vector<vector<int>> dist_fire, dist_jihoon;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<string> field;
    queue<pair<int, int>> q;
    pair<int, int> jihoon({ -1,-1 });
    dist_fire.assign(r, vector<int>(c, 2'000'000));
    dist_jihoon.assign(r, vector<int>(c, 2'000'000));
    for (int i = 0; i < r; i++) {
        string tmp;
        cin >> tmp;
        field.push_back(tmp);
        for (int j = 0; j < c; j++) {
            if (tmp[j] == 'J') jihoon = { i,j };
            else if (tmp[j] == 'F') {
                dist_fire[i][j] = 0;
                q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxtR = cur.first + dr[i];
            int nxtC = cur.second + dc[i];
            if (nxtR < 0 || nxtR >= r || nxtC < 0 || nxtC >= c) continue;
            if (dist_fire[nxtR][nxtC] != 2'000'000 || field[nxtR][nxtC] == '#') continue;
            dist_fire[nxtR][nxtC] = dist_fire[cur.first][cur.second] + 1;
            q.push({ nxtR,nxtC });
        }
    }

    dist_jihoon[jihoon.first][jihoon.second] = 0;
    q.push(jihoon);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxtR = cur.first + dr[i];
            int nxtC = cur.second + dc[i];
            if (nxtR < 0 || nxtR >= r || nxtC < 0 || nxtC >= c) {
                cout << dist_jihoon[cur.first][cur.second] + 1;
                return 0;
            }
            if (dist_jihoon[nxtR][nxtC] != 2'000'000 || field[nxtR][nxtC] == '#' || field[nxtR][nxtC] == 'F') continue;
            if (dist_fire[nxtR][nxtC] <= dist_jihoon[cur.first][cur.second] + 1) continue;
            dist_jihoon[nxtR][nxtC] = dist_jihoon[cur.first][cur.second] + 1;
            q.push({ nxtR,nxtC });
        }
    }

    cout << "IMPOSSIBLE";
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
