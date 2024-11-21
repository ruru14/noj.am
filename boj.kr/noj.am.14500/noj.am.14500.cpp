#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visit;

int n, m, ans = 0;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void dfs(int r, int c, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nxtR = r + dr[i];
        int nxtC = c + dc[i];
        if (nxtR < 0 || nxtC < 0 || nxtR > n || nxtC > m) continue;
        if (visit[nxtR][nxtC]) continue;
        visit[nxtR][nxtC] = true;
        dfs(nxtR, nxtC, depth + 1, sum + map[nxtR][nxtC]);
        visit[nxtR][nxtC] = false;
    }
}

void foo(int r, int c) {
    ans = max(ans, map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c + 1]); // ��
    ans = max(ans, map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c - 1]); // ��
    ans = max(ans, map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1]); // ��
    ans = max(ans, map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r - 1][c + 1]); // ��
}

int main() {
    cin >> n >> m;
    map.assign(n + 6, vector<int>(m + 6, 0));
    visit.assign(n + 6, vector<bool>(m + 6, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visit[i][j] = true;
            dfs(i, j, 1, map[i][j]);
            visit[i][j] = false;
            foo(i, j);
        }
    }

    cout << ans;
}