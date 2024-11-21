#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<char>> map;
vector<vector<vector<int>>> dist;

// Right, Down, Left, Up
int dh[] = { 0, 1, 0, -1 };
int dw[] = { 1, 0, -1, 0 };
int h, w;


void dijkstra(int idx, int startH, int startW) {
    deque<pair<int, int>> pos;
    int curH, curW;
    int nxtH, nxtW;
    dist[idx][startH][startW] = 0;
    pos.push_front(make_pair(startH, startW));

    while (!pos.empty()) {
        curH = pos.front().first;
        curW = pos.front().second;
        pos.pop_front();

        for (int i = 0; i < 4; i++) {
            nxtH = curH + dh[i];
            nxtW = curW + dw[i];
            if (nxtH < 0 || nxtW < 0 || nxtH > h + 1 || nxtW > w + 1) continue; // Out of range
            if (dist[idx][nxtH][nxtW] >= 0 || map[nxtH][nxtW] == '*') continue; // Wall
            if (map[nxtH][nxtW] == '.' || map[nxtH][nxtW] == '$') {
                dist[idx][nxtH][nxtW] = dist[idx][curH][curW];
                pos.push_front(make_pair(nxtH, nxtW));
            } else if (map[nxtH][nxtW] == '#') {
                dist[idx][nxtH][nxtW] = dist[idx][curH][curW] + 1;
                pos.push_back(make_pair(nxtH, nxtW));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc, foo, minDist;
    vector<pair<int, int>> prisoner;
    cin >> tc;

    while (tc-- > 0) {
        minDist = 99999999;
        foo = 99999999;
        cin >> h >> w;
        map.assign(h + 2, vector<char>(w + 2, '.'));
        dist.assign(3, vector<vector<int>>(h + 2, vector<int>(w + 2, -1)));
        prisoner.clear();
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '$') {
                    prisoner.push_back(make_pair(i, j));
                }
            }
        }

        dijkstra(0, 0, 0);
        dijkstra(1, prisoner[0].first, prisoner[0].second);
        dijkstra(2, prisoner[1].first, prisoner[1].second);

        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (map[i][j] == '*') continue;
                if (dist[0][i][j] == -1 || dist[1][i][j] == -1 || dist[2][i][j] == -1) continue;
                foo = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
                if (map[i][j] == '#') foo -= 2;
                minDist = min(minDist, foo);
            }
        }
        cout << minDist << "\n";
    }
}