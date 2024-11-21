#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<char>> cave;
vector<vector<bool>> visit;
// Right, Down, Left, Up
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
bool dropDown = false;

bool floorCheck(set<pair<int, int>, greater<>> cluster) {
    int minRow = 0;
    for (auto& i : cluster) {
        if (i.first > minRow) minRow = i.first;
        if ((cluster.find(make_pair(i.first + 1, i.second)) == cluster.end() && cave[i.first + 1][i.second] == 'x')
            || i.first == r) return true;
    }
    return false;
}

void dropX(int row, int col) {
    queue<pair<int, int>> bfs;
    set<pair<int, int>, greater<>> cluster;
    bfs.push(make_pair(row, col));
    cluster.insert(make_pair(row, col));
    visit[row][col] = true;
    int minRow = row;
    int cnt = 0;

    while (!bfs.empty()) {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        if (cur.first > minRow) minRow = cur.first;

        for (int i = 0; i < 4; i++) {
            if ((!visit[cur.first + dr[i]][cur.second + dc[i]]) && (cave[cur.first + dr[i]][cur.second + dc[i]] == 'x')) {
                bfs.push(make_pair(cur.first + dr[i], cur.second + dc[i]));
                cluster.insert(make_pair(cur.first + dr[i], cur.second + dc[i]));
                visit[cur.first + dr[i]][cur.second + dc[i]] = true;
            }
        }
    }

    while (!floorCheck(cluster)) {
        set<pair<int, int>, greater<>> tmp;
        dropDown = true;
        for (auto& i : cluster) {
            cave[i.first + 1][i.second] = 'x';
            visit[i.first + 1][i.second] = true;
            cave[i.first][i.second] = '.';
            tmp.insert(make_pair(i.first + 1, i.second));
        }
        cluster = tmp;
    }
}

int main() {
    int n;
    bool isLeft = true;
    cin >> r >> c;
    cave.assign(r + 2, vector<char>(c + 2, '.'));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> cave[i][j];
        }
    }

    cin >> n;

    while (n-- > 0) {
        int stick;
        cin >> stick;
        int pos = isLeft ? 0 : c;
        int dest = isLeft ? c : 0;
        int dir = isLeft ? 1 : -1;
        for (pos; pos != dest; pos += dir) {
            if (cave[r - stick + 1][pos] == 'x') {
                cave[r - stick + 1][pos] = '.';
                break;
            }
        }

        do {
            dropDown = false;
            visit.assign(r + 2, vector<bool>(c + 2, false));
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if ((!visit[i][j]) && (cave[i][j] == 'x')) {
                        dropX(i, j);
                    }
                }
            }
        } while (dropDown);

        isLeft = !isLeft;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << cave[i][j];
        }
        cout << "\n";
    }

}