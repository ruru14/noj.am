// noj.am.13459.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y = 1;
    int x = 1;
    bool operator==(const Pos& a) const {
        return y == a.y && x == a.x;
    }
    bool operator!=(const Pos& a) const {
        return !(*this == a);
    }
};

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int y, x;
Pos posR, posB, posGoal;
vector<string> board;

int swapLength(const vector<int>& arr) {
    int cur = -1;
    int length = 0;
    for (auto& i : arr) {
        if (i != cur) {
            cur = i;
            length++;
        }
    }

    return length;
}

void bfs() {
    bool visit[11][11][11][11] = {};
    visit[posR.y][posR.x][posB.y][posB.x] = true;
    int length = 11;

    queue<pair<vector<int>, pair<Pos, Pos>>> q;
    q.push({ vector<int>(), {posR, posB} });

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        vector<int> route = cur.first;
        Pos curR = cur.second.first;
        Pos curB = cur.second.second;

        for (int i = 0; i < 4; i++) {
            Pos nxtR = curR;
            Pos nxtB = curB;
            bool holeR = false, holeB = false;

            while (true) {
                Pos tmpR = nxtR;
                Pos tmpB = nxtB;

                Pos foo = { tmpR.y + dy[i], tmpR.x + dx[i] };
                if (!holeR && (board[foo.y][foo.x] != '#' && (foo != tmpB))) {
                    tmpR.y += dy[i];
                    tmpR.x += dx[i];
                    if (board[tmpR.y][tmpR.x] == 'O') {
                        tmpR = { 0,0 };
                        holeR = true;
                    }
                }

                foo = { tmpB.y + dy[i], tmpB.x + dx[i] };
                if (!holeB && (board[foo.y][foo.x] != '#' && (foo != tmpR))) {
                    tmpB.y += dy[i];
                    tmpB.x += dx[i];
                    if (board[tmpB.y][tmpB.x] == 'O') {
                        tmpB = { 0,0 };
                        holeB = true;
                    }
                }

                if (tmpR == nxtR && tmpB == nxtB) break;
                nxtR = tmpR;
                nxtB = tmpB;
            }

            if (holeB) continue;
            if (holeR) {
                length = min(length, swapLength(route) + 1);
                continue;
            }

            if (!visit[nxtR.y][nxtR.x][nxtB.y][nxtB.x]) {
                vector<int> nxtRoute(route);
                nxtRoute.push_back(i);
                visit[nxtR.y][nxtR.x][nxtB.y][nxtB.x] = true;
                q.push({ nxtRoute,{nxtR,nxtB} });
            }
        }
    }

    if (length >= 11) cout << 0;
    else cout << 1;
}

int main() {
    cin >> y >> x;
    board.assign(y, "");

    for (int i = 0; i < y; i++) {
        cin >> board[i];
    }

    for (int row = 0; row < y; row++) {
        for (int col = 0; col < x; col++) {
            if (board[row][col] == 'R') {
                board[row][col] = '.';
                posR.y = row;
                posR.x = col;
            } else if (board[row][col] == 'B') {
                board[row][col] = '.';
                posB.y = row;
                posB.x = col;
            } else if (board[row][col] == 'O') {
                posGoal.y = row;
                posGoal.x = col;
            }
        }
    }
    bfs();
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
