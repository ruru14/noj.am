// noj.am.1202.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n, { 0, 0 });
    vector<int> bag(k, 0);

    for (int i = 0; i < n; i++) cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < k; i++) cin >> bag[i];

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    
    priority_queue<int> pq;
    int idx = 0;
    for (auto& i : bag) {
        while (idx < n && jewel[idx].first <= i) {
            pq.push(jewel[idx++].second);
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
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
