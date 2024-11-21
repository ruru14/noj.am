#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> dist;
vector<vector<int>> map;

// R, D, L, U
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void dijkstra(int startY, int startX) {
    priority_queue<pair<int, pair<int, int>>> coord;
    int curCost, curY, curX;
    int nxtCost, nxtY, nxtX;
    dist[startY][startX] = map[startY][startX];
    coord.push(make_pair(-map[startY][startX], make_pair(startY, startX)));

    while (!coord.empty()) {
        curCost = -coord.top().first;
        curY = coord.top().second.first;
        curX = coord.top().second.second;
        coord.pop();

        for (int i = 0; i < 4; i++) {
            nxtY = curY + dy[i];
            nxtX = curX + dx[i];
            nxtCost = curCost + map[nxtY][nxtX];
            if (nxtCost < dist[nxtY][nxtX]) {
                dist[nxtY][nxtX] = nxtCost;
                coord.push(make_pair(-nxtCost, make_pair(nxtY, nxtX)));
            }
        }
    }
}

int main() {
    int n, cnt = 1;
    cin >> n;

    while (n != 0) {
        map.assign(n + 2, vector<int>(n + 2, 99999));
        dist.assign(n + 2, vector<int>(n + 2, 99999));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }
        dijkstra(1, 1);
        cout << "Problem " << cnt++ << ": " << dist[n][n] << "\n";

        cin >> n;
    }
}