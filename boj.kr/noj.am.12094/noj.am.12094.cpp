// noj.am.12094.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

#define TARGET 10

using namespace std;

int n;
int board[20][20];
int globalMax;

inline int getMax(int arr[][20]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, arr[i][j]);
        }
    }
    return result;
}

inline bool isSame(int a[][20], int b[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }

    return true;
}

void printArr(int arr[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << arr[i][j] << " ";
        cout << "\n";
    }
}

inline int moveRight(int arr[20]) {
    int tmp[20] = { 0 };
    int curMax = 0;
    int pos = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) continue;
        if (tmp[pos] == 0) tmp[pos] = arr[i];
        else {
            if (tmp[pos] == arr[i]) tmp[pos--] *= 2;
            else tmp[--pos] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
        curMax = max(curMax, arr[i]);
    }

    return curMax;
}

inline int moveLeft(int arr[20]) {
    int tmp[20] = { 0 };
    int curMax = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        if (tmp[pos] == 0) tmp[pos] = arr[i];
        else {
            if (tmp[pos] == arr[i]) tmp[pos++] *= 2;
            else tmp[++pos] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
        curMax = max(curMax, arr[i]);
    }

    return curMax;
}


inline int moveUp(int arr[][20]) {
    int tmp[20][20] = { 0, };
    int curMax = 0;
    for (int i = 0; i < n; i++) {
        int pos = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 0) continue;
            if (tmp[pos][i] == 0) tmp[pos][i] = arr[j][i];
            else {
                if (tmp[pos][i] == arr[j][i]) tmp[pos++][i] *= 2;
                else tmp[++pos][i] = arr[j][i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = tmp[i][j];
            curMax = max(curMax, arr[i][j]);
        }
    }

    return curMax;
}

inline int moveDown(int arr[][20]) {
    int tmp[20][20] = { 0, };
    int curMax = 0;
    for (int i = 0; i < n; i++) {
        int pos = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (arr[j][i] == 0) continue;
            if (tmp[pos][i] == 0) tmp[pos][i] = arr[j][i];
            else {
                if (tmp[pos][i] == arr[j][i]) tmp[pos--][i] *= 2;
                else tmp[--pos][i] = arr[j][i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = tmp[i][j];
            curMax = max(curMax, arr[i][j]);
        }
    }

    return curMax;
}

inline void copyBoard(int target[][20], int source[][20]) {
    for (int i = 0; i < n; i++) {
        memcpy(target[i], source[i], sizeof(int) * n);
    }
}

void backtrack(int curBoard[][20], int cnt) {
    if (cnt == TARGET) {
        globalMax = max(getMax(curBoard), globalMax);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int curMax = 0;
        int nxtBoard[20][20], tmp[20][20];
        copyBoard(nxtBoard, curBoard);
        if (i == 0) { // Right
            for (int j = 0; j < n; j++) curMax = max(curMax, moveRight(nxtBoard[j]));
        } else if (i == 2) { // Left
            for (int j = 0; j < n; j++) curMax = max(curMax, moveLeft(nxtBoard[j]));
        } else if (i == 1) { // Down
            curMax = max(curMax, moveDown(nxtBoard));
        } else { // Up
            curMax = max(curMax, moveUp(nxtBoard));
        }

        if (globalMax >= (curMax << TARGET - cnt)) continue;
        if (isSame(curBoard, nxtBoard)) continue;
        backtrack(nxtBoard, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            globalMax = max(globalMax, board[i][j]);
        }
    }

    backtrack(board, 0);
    cout << globalMax;
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
