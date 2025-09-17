// noj.am.1368.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int mincost = 0, edge = 0;
    cin >> n;
    vector<bool> visit(n + 1, false);
    visit[0] = true;
    vector<vector<pair<int, int>>> cost(n + 1);
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> q;
    for (int i = 1; i <= n; i++) {
        int foo;
        cin >> foo;
        q.push({ foo, 0, i });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int foo;
            cin >> foo;
            if (i == j) continue;
            cost[i].push_back({ j, foo });
            cost[j].push_back({ i, foo });
        }
    }

    while (!q.empty()) {
        int c, from, to;
        tie(c, from, to) = q.top();
        q.pop();
        if (visit[to]) continue;

        visit[to] = true;
        mincost += c;
        edge++;
        for (auto& i : cost[to]) {
            if (!visit[i.first]) {
                q.push({ i.second, to, i.first });
            }
        }

        if (edge == n) break;
    }

    cout << mincost;
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
