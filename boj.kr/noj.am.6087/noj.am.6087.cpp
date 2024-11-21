#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/*
* 1000 = 8
* 0100 = 4
* 0010 = 2
* 0001 = 1
* 1010 = 10
* 0101 = 5
*/
// Right, Down, Left, Up
int dh[] = {
    0, 0, 1, 0,
    0, 0, 0, 0,
    -1,
};
int dw[] = {
    0, 1, 0, 0,
    -1, 0, 0, 0,
    0,
};
int dir[] = {
    0, 5, 10, 0,
    5, 0, 0, 0,
    10,
};

struct Coord {
    int dist;
    int dir;
    int curH;
    int curW;

    Coord(int dist, int dir, int curH, int curW) : dist(dist), dir(dir), curH(curH), curW(curW) {}

    bool operator<(const Coord c) const {
        return dist > c.dist;
    }
};


vector<vector<int>> bfs(int startH, int startW, vector<vector<char>> map) {
    priority_queue<Coord> pq;
    vector<vector<int>> dist(map.size(), vector<int>(map[0].size(), 200000));
    pq.push(Coord{ 0, 15, startH, startW });
    dist[startH][startW] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        for (int i = 1; i < (1 << 4); i <<= 1) {
            int nxtH = top.curH + dh[i];
            int nxtW = top.curW + dw[i];
            if (map[nxtH][nxtW] == '*') continue;
            if (top.dir & i) {
                int nxtCost = top.dist;
                if (dist[nxtH][nxtW] >= nxtCost) {
                    dist[nxtH][nxtW] = nxtCost;
                    pq.push(Coord{ nxtCost, i, nxtH, nxtW });
                }
            } else {
                int nxtCost = top.dist + 1;
                if (dist[nxtH][nxtW] > nxtCost) {
                    dist[nxtH][nxtW] = nxtCost;
                    pq.push(Coord{ nxtCost, i, nxtH, nxtW });
                }
            }
        }
    }

    return dist;
}

int main() {
    int w, h;
    vector<vector<char>> map;
    vector<pair<int, int>> connection;
    cin >> w >> h;
    map.assign(h + 2, vector<char>(w + 2, '*'));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'C') {
                connection.push_back(make_pair(i, j));
            }
        }
    }

    vector<vector<int>> ans = bfs(connection[0].first, connection[0].second, map);

    cout << ans[connection[1].first][connection[1].second];
}