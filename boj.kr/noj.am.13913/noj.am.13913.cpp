// noj.am.13913.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
    int cur;
    int t;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> parent(200'001, -1);
    vector<int> ans;
    parent[n] = n;
    Pos p;
    p.cur = n;
    p.t = 0;

    queue<Pos> q;
    q.push(p);

    while (!q.empty()) {
        auto c = q.front(); q.pop();

        if (c.cur == k) {
            cout << c.t << "\n";
            while (c.cur != parent[c.cur]) {
                ans.push_back(c.cur);
                c.cur = parent[c.cur];
            }
            ans.push_back(c.cur);
            break;
        }

        if (c.cur - 1 >= 0 && parent[c.cur - 1] == -1) {
            Pos nxt(c);
            parent[c.cur - 1] = c.cur;
            nxt.cur = nxt.cur - 1;
            nxt.t = nxt.t + 1;
            q.push(nxt);
        }

        if (c.cur + 1 < parent.size() && parent[c.cur + 1] == -1) {
            Pos nxt(c);
            parent[c.cur + 1] = c.cur;
            nxt.cur = nxt.cur + 1;
            nxt.t = nxt.t + 1;
            q.push(nxt);
        }

        if (c.cur * 2 < parent.size() && parent[c.cur * 2] == -1) {
            Pos nxt(c);
            parent[c.cur * 2] = c.cur;
            nxt.cur = nxt.cur * 2;
            nxt.t = nxt.t + 1;
            q.push(nxt);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
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
