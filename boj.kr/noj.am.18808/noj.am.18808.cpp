// noj.am.18808.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m, k;
vector<vector<int>> laptop;
int r, c;
vector<vector<int>> sticker;

bool isValid(int row, int col) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (laptop[row + i][col + j] == 1 && sticker[i][j] == 1) return false;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(laptop[row + i][col + j] == 0)
                laptop[row + i][col + j] = sticker[i][j];
        }
    }

    return true;
}

void rotate() {
    vector<vector<int>> tmp(c, vector<int>(r, 0));

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            tmp[i][j] = sticker[r - 1 - j][i];
        }
    }
    sticker = tmp;
    swap(r, c);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    cin >> n >> m >> k;
    laptop.assign(n, vector<int>(m, 0));

    while (k--) {
        int size = 0;
        cin >> r >> c;
        sticker.assign(r, vector<int>(c, 0));
        for (int i = 0; i <r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
                if (sticker[i][j] == 1) size++;
            }
        }

        for (int k = 0; k < 4; k++) {
            bool pasted = false;
            for (int i = 0; i <= n - r; i++) {
                for (int j = 0; j <= m - c; j++) {
                    if (!pasted && isValid(i, j)) {
                        pasted = true;
                        ans += size;
                    }
                }
            }
            if (pasted) break;
            rotate();
        }

    }

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
