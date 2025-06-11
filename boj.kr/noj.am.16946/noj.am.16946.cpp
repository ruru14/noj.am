// noj.am.16946.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int row, col;
vector<string> board;
vector<vector<int>> boardId;

int bfs(const pair<int,int> start, int id) {
    queue<pair<int, int>> q;
    q.push(start);
    int size = 0;

    while (!q.empty()) {
        auto cur = q.front();
        boardId[cur.first][cur.second] = id;
        q.pop();
        size++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt({ cur.first + dy[i], cur.second + dx[i] });
            if (nxt.first < 0 || nxt.first >= row || nxt.second < 0 || nxt.second >= col) continue;

            if (board[nxt.first][nxt.second] == '1') continue;
            if (boardId[nxt.first][nxt.second] != -1) continue;
            boardId[nxt.first][nxt.second] = id;
            q.push(nxt);
        }
    }
    return size;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> row >> col;
    board.assign(row, "");
    boardId.assign(row, vector<int>(col, -1));
    vector<int> idSize(row * col, 0);
    vector<vector<int>> ans(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) cin >> board[i];

    int id = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == '0' && boardId[i][j] == -1) {
                idSize[id] = bfs({ i,j }, id);
                id++;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == '1') {
                int sum = 0;
                set<int> bar;
                for (int d = 0; d < 4; d++) {
                    int nxtI = i + dy[d];
                    int nxtJ = j + dx[d];
                    if (nxtI < 0 || nxtI >= row || nxtJ < 0 || nxtJ >= col) continue;
                    if (board[nxtI][nxtJ] == '1') continue;
                    bar.insert(boardId[nxtI][nxtJ]);
                }
                for (auto& i : bar) sum += idSize[i];
                ans[i][j] = (sum + 1) % 10;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
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
