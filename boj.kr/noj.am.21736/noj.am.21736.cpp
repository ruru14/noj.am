#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int startX, startY;
int map[601][601];
bool visit[601][601];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool isValid(int x, int y) {
    if (x < 0 || y < 0) return false;
    if (x >= n || y >= m) return false;
    return true;
}

int main() {
    cin >> n >> m;
    int answer = 0;
    char info;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> info;
            switch (info) {
            case 'I':
                startX = i;
                startY = j;
                map[i][j] = 3;
                break;
            case 'O':
                break;
            case 'X':
                map[i][j] = 1;
                break;
            case 'P':
                map[i][j] = 2;
                break;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (map[current.first][current.second] == 2) answer++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> next(current.first + dx[i], current.second + dy[i]);
            if (isValid(next.first, next.second)) {
                if (!visit[next.first][next.second] && map[next.first][next.second] != 1) {
                    visit[next.first][next.second] = !visit[next.first][next.second];
                    q.push(next);
                }
            }
        }

    }

    if (answer == 0) cout << "TT";
    else cout << answer;
}