#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isClean;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

struct RobotInfo {
    int dir;
    int curR;
    int curC;
};

int cleaner(int mapR, int mapC, int startR, int startC, int dir) {
    int ans = 1;
    queue<RobotInfo> queue;
    queue.push({ dir, startR, startC });

    while (!queue.empty()) {
        RobotInfo curInfo = queue.front();
        queue.pop();
        isClean[curInfo.curR][curInfo.curC] = true;
        bool foo = false;

        for (int i = 1; i <= 4; i++) {
            int nxtDir = curInfo.dir - i;
            if (nxtDir < 0) nxtDir += 4;
            int nxtR = curInfo.curR + dr[nxtDir];
            int nxtC = curInfo.curC + dc[nxtDir];
            if (nxtR < 0 || nxtC < 0 || nxtR >= mapR || nxtC >= mapC) continue;
            if (map[nxtR][nxtC] == 1) continue;
            if (!isClean[nxtR][nxtC] && map[nxtR][nxtC] == 0) {
                ans++;
                foo = true;
                queue.push({ nxtDir, nxtR, nxtC });
                break;
            }
        }

        if (!foo) {
            int backDir = curInfo.dir - 2;
            if (backDir < 0) backDir += 4;
            int nxtR = curInfo.curR + dr[backDir];
            int nxtC = curInfo.curC + dc[backDir];
            if (nxtR < 0 || nxtC < 0 || nxtR >= mapR || nxtC >= mapC) continue;
            if (map[nxtR][nxtC] == 1) break;
            else if (map[nxtR][nxtC] == 0) queue.push({ curInfo.dir, nxtR, nxtC });
        }
    }

    return ans;
}

int main() {
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    map.assign(n, vector<int>(m, 0));
    isClean.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cout << cleaner(n, m, r, c, d);
}