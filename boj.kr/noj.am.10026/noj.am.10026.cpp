#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<char>> picture;
vector<vector<bool>> visitN, visitD;

// R, D, L, U
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void bfs(int startY, int startX, bool flag) {
    queue<pair<int, int>> queue;
    int curY, curX;
    queue.push(make_pair(startY, startX));
    char area = picture[startY][startX];
    if (flag) visitD[startY][startX] = true;
    else visitN[startY][startX] = true;

    while (!queue.empty()) {
        curY = queue.front().first;
        curX = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (flag) {
                if (!visitD[nextY][nextX]) {
                    if (area == 'R' || area == 'G') {
                        if (picture[nextY][nextX] == 'R' || picture[nextY][nextX] == 'G') {
                            visitD[nextY][nextX] = true;
                            queue.push(make_pair(nextY, nextX));
                        }
                    } else {
                        if (picture[nextY][nextX] == area) {
                            visitD[nextY][nextX] = true;
                            queue.push(make_pair(nextY, nextX));
                        }
                    }
                }
            } else {
                if (!visitN[nextY][nextX]) {
                    if (picture[nextY][nextX] == area) {
                        visitN[nextY][nextX] = true;
                        queue.push(make_pair(nextY, nextX));
                    }
                }
            }


        }
    }
}

int main() {
    int n, ansN = 0, ansD = 0;
    cin >> n;
    picture.assign(n + 2, vector<char>(n + 2, '.'));
    visitN.assign(n + 2, vector<bool>(n + 2, false));
    visitD.assign(n + 2, vector<bool>(n + 2, false));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> picture[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visitN[i][j]) {
                bfs(i, j, false);
                ansN++;
            }
            if (!visitD[i][j]) {
                bfs(i, j, true);
                ansD++;
            }
        }
    }
    cout << ansN << " " << ansD;
}