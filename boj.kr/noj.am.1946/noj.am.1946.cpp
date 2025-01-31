// noj.am.1946.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, ans = 1;
        cin >> n;
        priority_queue<pair<int, int>> pq;

        while (n--) {
            int a, b;
            cin >> a >> b;
            pq.push(make_pair(-a, b));
        }

        int max = pq.top().second;
        pq.pop();
        while (!pq.empty()) {
            auto tmp = pq.top(); pq.pop();
            if (max > tmp.second) {
                ans++;
                max = tmp.second;
            }
        }
        cout << ans << "\n";
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
