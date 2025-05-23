// noj.am.19951.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    vector<int> ans(n + 1, 0);
    vector<int> diff(n + 2, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        diff[a] += c;
        diff[b + 1] += (-c);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += diff[i];
        ans[i] = sum + arr[i];
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
