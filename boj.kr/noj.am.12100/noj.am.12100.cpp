// noj.am.12100.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int ans = 0;

void moveArray(vector<int>& arr) {
    int size = arr.size();
    reverse(arr.begin(), arr.end());

    deque<int> dq;
    for (auto& i : arr) {
        if (i == 0) continue;
        if (dq.empty()) {
            dq.push_back(i);
        } else {
            if (dq.back() == i) {
                dq.pop_back();
                dq.push_back(i * 2);
                dq.push_back(-1);
            } else {
                dq.push_back(i);
            }
        }
    }
    arr.clear();
    while (!dq.empty()) {
        if (dq.front() == -1) {
            dq.pop_front();
            continue;
        }
        arr.push_back(dq.front());
        dq.pop_front();
    }
    while (arr.size() != size) arr.push_back(0);
    reverse(arr.begin(), arr.end());
}

vector<vector<int>> moveBlock(vector<vector<int>> board, int direction) {
    int size = board.size();

    if (direction == 0 || direction == 2) {
        for (int i = 0; i < size; i++) {
            vector<int> row = board[i];
            if (direction == 0) reverse(row.begin(), row.end());

            moveArray(row);

            if (direction == 0) reverse(row.begin(), row.end());
            board[i] = row;
        }
    } else {
        for (int j = 0; j < size; j++) {
            vector<int> col;
            for (int i = 0; i < size; i++) {
                col.push_back(board[i][j]);
            }
            if (direction == 1) reverse(col.begin(), col.end());

            moveArray(col);

            if (direction == 1) reverse(col.begin(), col.end());
            for (int i = 0; i < size; i++) {
                board[i][j] = col[i];
            }
        }
    }

    return board;
}

void backtrack(vector<vector<int>> board, int n, int curMax) {
    for (auto& i : board) {
        for (auto& j : i) {
            curMax = max(curMax, j);
        }
    }
    ans = max(ans, curMax);

    if (n == 5) return;

    int remainMax = curMax << (5 - n);
    if (remainMax <= ans) return;

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> nxt = moveBlock(board, i);
        if (nxt == board) continue;
        backtrack(nxt, n + 1, curMax);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    backtrack(board, 0, 0);
    cout << ans;
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
