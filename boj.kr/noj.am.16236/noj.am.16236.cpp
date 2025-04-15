// noj.am.16236.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 555

using namespace std;

int n, sharkSize = 2, eat = 0;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<vector<int>> map;

bool isValid(pair<int, int> start) {
    if (start.first < 0 || start.first >= n) return false;
    if (start.second < 0 || start.second >= n) return false;
    return true;
}

int dijkstra(pair<int, int>& start) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[start.first][start.second] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int curDist = pq.top().first;
        auto curPos = pq.top().second;
        pq.pop();

        if (curDist > dist[curPos.first][curPos.second]) continue;

        for (int i = 0; i < 4; i++) {
            int nxtY = curPos.first + dy[i];
            int nxtX = curPos.second + dx[i];
            int nxtDist = curDist + 1;
            if (!isValid({ nxtY,nxtX })) continue;
            if (map[nxtY][nxtX] == 9 || map[nxtY][nxtX] > sharkSize) continue;
            if (dist[nxtY][nxtX] > nxtDist) {
                dist[nxtY][nxtX] = nxtDist;
                pq.push({ dist[nxtY][nxtX], {nxtY,nxtX} });
            }
        }
    }

    int minDist = INF;
    pair<int, int> nxtPos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == start.first && j == start.second) continue;
            if ((map[i][j] != 0 && map[i][j] < sharkSize) && dist[i][j] < minDist) {
                minDist = dist[i][j];
                nxtPos = { i,j };
            }
        }
    }

    if (minDist == INF) return 0;
    else {
        map[start.first][start.second] = 0;
        map[nxtPos.first][nxtPos.second] = 9;
        eat++;
        if (eat == sharkSize) {
            eat = 0;
            sharkSize++;
        }
        start = nxtPos;
        return minDist;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    pair<int, int> sharkPos({ 0,0 });
    cin >> n;
    map.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) sharkPos = { i,j };
        }
    }

    while (true) {
        int nxtMove = dijkstra(sharkPos);
        ans += nxtMove;

        if (nxtMove == 0) break;
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
