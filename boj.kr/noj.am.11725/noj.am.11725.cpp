// noj.am.11725.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> answer(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int foo, bar;
        cin >> foo >> bar;
        graph[foo].push_back(bar);
        graph[bar].push_back(foo);
    }

    queue<int> q;
    q.push(1);
    vector<bool> visit(n + 1, false);
    visit[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& i : graph[cur]) {
            if (!visit[i]) {
                visit[i] = true;
                answer[i] = cur;
                q.push(i);
            }
        }
    }

    for (int i = 2; i < answer.size(); i++) cout << answer[i] << "\n";
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
