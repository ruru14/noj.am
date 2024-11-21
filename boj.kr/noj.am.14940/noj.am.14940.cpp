// noj.am14940.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <utility>

using namespace std;

int map[1001][1001];
int dist[1001][1001];
int n, m;

// up right down left
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool isValid(pair<int, int> point) {
    if (point.first < 0 || point.second < 0) return false;
    if (point.first >= n || point.second >= m) return false;
    return true;
}

void bfs(pair<int, int> start) {
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    visit[start.first][start.second] = true;

    queue<pair<int, int>> queue;
    queue.push(start);

    while (!queue.empty()) {
        pair<int, int> point = queue.front();
        int cost = dist[point.first][point.second];
        queue.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next(point.first + dx[i], point.second + dy[i]);
            if (isValid(next) && map[next.first][next.second] != 0) {
                if (dist[next.first][next.second] > cost + 1) dist[next.first][next.second] = cost + 1;
                if (!visit[next.first][next.second]) {
                    visit[next.first][next.second] = true;
                    queue.push(next);
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int tmp = 0;
    pair<int, int> start(0, 0);
    //vector<vector<int>> map, distance;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            map[i][j] = tmp;
            dist[i][j] = INT_MAX;
            if (tmp == 2) {
                start.first = i;
                start.second = j;
            }
        }
    }
    dist[start.first][start.second] = 0;

    bfs(start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == INT_MAX) {
                if (map[i][j] == 0) cout << "0 ";
                else cout << "-1 ";
            } else cout << dist[i][j] << " ";
        }
        cout << "\n";
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
