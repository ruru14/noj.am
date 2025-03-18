// noj.am.12851.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define INF 1'111'111'111

int ds[] = { 1, -1, 2 };

int min_time = INF, min_cnt = 0;

void foo(int n, int k) {
    vector<int> visit(200001, INF);
    queue<pair<int, int>> q; // Pos, Time
    q.push(make_pair(n, 0));

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nextPos = current.first;
            if (i == 2) nextPos *= ds[i];
            else nextPos += ds[i];

            if ((nextPos > 200000 || nextPos < 0) ||
                min_time < current.second) 
                continue;

            if (nextPos == k) {
                if (min_time == current.second + 1) min_cnt++;
                else if (min_time > current.second + 1) {
                    min_cnt = 1;
                    min_time = current.second + 1;
                }
            }

            if (visit[nextPos] >= current.second + 1) {
                visit[nextPos] = current.second + 1;
                q.push(make_pair(nextPos, current.second + 1));
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    if (n == k) cout << "0\n1";
    else {
        foo(n, k);
        cout << min_time << "\n" << min_cnt;
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
