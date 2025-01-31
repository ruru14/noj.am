// noj.am.15663.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    set<vector<int>> answer;

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    do {
        vector<int> foo;
        for (int i = 0; i < m; i++) {
            foo.push_back(arr[i]);
        }
        answer.insert(foo);
    } while (next_permutation(arr.begin(), arr.end()));

    for (auto& i : answer) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
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
