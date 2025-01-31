// noj.am.16928.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = n + m;
    vector<int> graph(101);
    vector<bool> visit(101, false);

    while (cnt--) {
        int foo, bar;
        cin >> foo >> bar;
        graph[foo] = bar;
    }

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == 100) {
            cout << cur.second;
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int nxt = cur.first + i;
            if (nxt > 100) continue;
            if (!visit[nxt]) {
                visit[nxt] = true;
                if (graph[nxt]) {
                    q.push({ graph[nxt], cur.second + 1 });
                } else {
                    q.push({ nxt, cur.second + 1 });
                }
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
