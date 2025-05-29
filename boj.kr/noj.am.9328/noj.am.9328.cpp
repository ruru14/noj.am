// noj.am.9328.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int dw[] = { 1,0,-1,0 };
int dh[] = { 0,1,0,-1 };

int bfs(vector<string> m, int h, int w, vector<bool> key) {
    vector<vector<bool>> visit(h + 2, vector<bool>(w + 2, false));
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visit[0][0] = true;
    int doc = 0;

    vector<pair<int, int>> res[26];

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxtH = cur.first + dh[i];
            int nxtW = cur.second + dw[i];

            if (nxtH < 0 || nxtH >= m.size() || nxtW < 0 || nxtW >= m[0].size()) continue;
            if (visit[nxtH][nxtW]) continue;

            char nxt = m[nxtH][nxtW];
            if (nxt == '*') continue;

            if (nxt >= 'A' && nxt <= 'Z') {
                if (key[nxt - 'A']) {
                    visit[nxtH][nxtW] = true;
                    q.push({ nxtH,nxtW });
                } else {
                    res[nxt - 'A'].push_back({ nxtH,nxtW });
                }
            } else if (nxt >= 'a' && nxt <= 'z') {
                if (!key[nxt - 'a']) {
                    key[nxt - 'a'] = true;
                    for (auto& i : res[nxt - 'a']) {
                        if (!visit[i.first][i.second]) {
                            visit[i.first][i.second] = true;
                            q.push(i);
                        }
                    }
                    res[nxt - 'a'].clear();
                }
                visit[nxtH][nxtW] = true;
                q.push({ nxtH,nxtW });
            } else {
                if (nxt == '$') doc++;
                visit[nxtH][nxtW] = true;
                q.push({ nxtH,nxtW });
            }
        }
    }

    return doc;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    vector<int> ans;

    while (tc--) {
        int h, w;
        cin >> h >> w;
        string foo;
        for (int i = 0; i < w + 2; i++) foo += '.';
        vector<string> m(h + 2, foo);
        for (int i = 0; i < h; i++) {
            string input;
            cin >> input;
            m[i + 1].replace(1, w, input);
        }
        string k;
        cin >> k;
        vector<bool> key(26, false);
        if (k != "0") {
            for (auto& i : k) key[i - 'a'] = true;
        }
        ans.push_back(bfs(m, h, w, key));
    }

    for (auto& i : ans) cout << i << "\n";
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
