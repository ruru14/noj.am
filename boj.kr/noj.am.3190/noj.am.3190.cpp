#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Timestamp {
    int time;
    char dir;
};

struct Snake {
    int curR;
    int curC;
    int dir;
};

vector<vector<int>> map;
queue<Timestamp> stamp;
deque<Snake> bam;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int main() {
    int n, k, l;
    int ans = 0;
    bool flag = false;
    cin >> n >> k;
    map.assign(n + 2, vector<int>(n + 2, 0));
    bam.push_front({ 1, 1, 0 });

    while (k--) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }

    cin >> l;

    while (l--) {
        int t;
        char d;
        cin >> t >> d;
        stamp.push({ t, d });
    }

    while (1) {
        auto curBam = bam.front();
        auto tailBam = bam.back();

        if (!stamp.empty()) {
            auto stampInfo = stamp.front();

            if (ans == stampInfo.time) {
                if (stampInfo.dir == 'L') {
                    curBam.dir--;
                    if (curBam.dir < 0) curBam.dir += 4;
                } else {
                    curBam.dir++;
                    if (curBam.dir >= 4) curBam.dir -= 4;
                }
                stamp.pop();
            }
        }

        int nxtR = curBam.curR + dr[curBam.dir];
        int nxtC = curBam.curC + dc[curBam.dir];
        if (nxtR <= 0 || nxtC <= 0 || nxtR > n || nxtC > n) {
            cout << ans + 1;
            return 0;
        }
        for (auto& i : bam) {
            if (nxtR == i.curR && nxtC == i.curC) {
                cout << ans + 1;
                return 0;
            }
        }
        bam.push_front({ nxtR, nxtC, curBam.dir });
        if (map[nxtR][nxtC] == 0) bam.pop_back();
        if (map[nxtR][nxtC] == 1) map[nxtR][nxtC] = 0;
        ans++;
    }

    cout << ans;
}