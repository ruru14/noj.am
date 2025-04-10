// noj.am.2638.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<int>> air;

bool isValidIdx(int y, int x) {
    if (y < 0 || y >= n ||
        x < 0 || x >= m) return false;
    return true;
}

void airUpdate(vector<vector<int>> map, vector<pair<int, int>> start) {
    queue<pair<int, int>> q;
    for (auto& i : start) {
        air[i.first][i.second] = 1;
        q.push(i);
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxtY = cur.first + dy[i];
            int nxtX = cur.second + dx[i];
            if (!isValidIdx(nxtY, nxtX)) continue;
            if (air[nxtY][nxtX] == 0 && map[nxtY][nxtX] == 0) {
                q.push(make_pair(nxtY, nxtX));
                air[nxtY][nxtX] = 1;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    air.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    
    airUpdate(map, vector<pair<int, int>>({{ 0,0 }}));

    while (true) {
        int melt = 0;
        vector<vector<int>> nxtMap(map);
        vector<pair<int, int>> nxtAir;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int adjY = i + dy[k];
                        int adjX = j + dx[k];
                        if (air[adjY][adjX] == 1) cnt++;
                        if (cnt >= 2) {
                            nxtMap[i][j] = 0;
                            nxtAir.push_back(make_pair(i, j));
                            melt++;
                            break;
                        }
                    }
                }
            }
        }

        map = nxtMap;
        airUpdate(map, nxtAir);
        if (melt == 0) break;
        else ans++;
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
