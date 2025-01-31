// noj.am.9019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    while (tc--) {
        int foo, bar;
        cin >> foo >> bar;
        queue<pair<int, string>> q;
        vector<bool> visit(10001, false);
        q.push({ foo, "" });
        visit[foo] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur.first == bar) {
                cout << cur.second << "\n";
                break;
            }

            int d = cur.first * 2;
            if (d >= 10000) d = d % 10000;
            if (!visit[d]) {
                q.push({ d, cur.second + 'D' });
                visit[d] = true;
            }

            int s = cur.first - 1;
            if (s < 0) s += 10000;
            if (!visit[s]) {
                q.push({ s, cur.second + 'S' });
                visit[s] = true;
            }

            int l = cur.first % 1000 * 10 + cur.first / 1000;
            if (!visit[l]) {
                q.push({ l, cur.second + 'L' });
                visit[l] = true;
            }

            int r = cur.first / 10 + (cur.first % 10) * 1000;
            if (!visit[r]) {
                q.push({ r,cur.second + 'R' });
                visit[r] = true;
            }
        }
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
