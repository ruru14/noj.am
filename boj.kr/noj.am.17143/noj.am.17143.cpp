// noj.am.17143.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Shark {
    int dir = 0;
    int dx = 0;
    int dy = 0;
    int size = 0;
    int cnt = 0;
    bool alive = false;
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int row, col, m;
    int ans = 0;
    cin >> row >> col >> m;
    vector<vector<Shark>> sharks(row, vector<Shark>(col));

    for (int i = 0; i < m; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Shark foo;
        foo.dir = d - 1;
        foo.dy = (dy[foo.dir] * c) % (2 * row - 2);
        foo.dx = (dx[foo.dir] * c) % (2 * col - 2);
        foo.size = e;
        foo.alive = true;
        sharks[a - 1][b - 1] = foo;
    }

    // Move fisher
    for (int fisher = 0; fisher < col; fisher++) {
        // Catch shark
        for (int i = 0; i < row; i++) {
            if (sharks[i][fisher].alive) {
                ans += sharks[i][fisher].size;
                sharks[i][fisher].alive = false;
                break;
            }
        }

        vector<vector<Shark>> nxtSharks(row, vector<Shark>(col));
        // Move shark
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (sharks[i][j].alive) {
                    int nxtI = i;
                    int nxtJ = j;
                    if (sharks[i][j].dx == 0) {
                        // Y (i) axis move
                        nxtI = i + sharks[i][j].dy;
                        int cycle = (row - 1) * 2;
                        nxtI = ((nxtI % cycle) + cycle) % cycle;

                        if (nxtI >= row) {
                            nxtI = cycle - nxtI;
                            sharks[i][j].dy *= -1;
                        }
                    } else {
                        // X (j) axis move
                        nxtJ = j + sharks[i][j].dx;
                        int cycle = (col - 1) * 2;
                        nxtJ = ((nxtJ % cycle) + cycle) % cycle;

                        if (nxtJ >= col) {
                            nxtJ = cycle - nxtJ;
                            sharks[i][j].dx *= -1;
                        }
                    }

                    if (nxtSharks[nxtI][nxtJ].alive) {
                        if (nxtSharks[nxtI][nxtJ].size < sharks[i][j].size) {
                            nxtSharks[nxtI][nxtJ] = sharks[i][j];
                        }
                    } else {
                        nxtSharks[nxtI][nxtJ] = sharks[i][j];
                    }
                }
            }
        }

        sharks = nxtSharks;
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
