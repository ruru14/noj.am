// noj.am.20303.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Group {
    int size = 0;
    int candy = 0;
};

int n, m, k, ans = 0;
vector<int> totalCandy;
vector<vector<int>> friends;
vector<bool> visit;
vector<Group> info;

Group bfs(int start) {
    Group result;
    queue<int> q;
    q.push(start);
    int size = 0;
    visit[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.size++;
        result.candy += totalCandy[cur];

        for (auto& nxt : friends[cur]) {
            if (!visit[nxt]) {
                q.push(nxt);
                visit[nxt] = true;
            }
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    totalCandy.assign(n + 1, 0);
    friends.assign(n + 1, vector<int>());
    visit.assign(n + 1, false);
    for (int i = 1; i <= n; i++) cin >> totalCandy[i];
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            info.push_back(bfs(i));
        }
    }

    vector<int> dp(3000, 0);
    for (auto& i : info) {
        for (int j = k; j >= i.size; j--) {
            dp[j] = max(dp[j], dp[j - i.size] + i.candy);
        }
    }

    cout << dp[k - 1];
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
