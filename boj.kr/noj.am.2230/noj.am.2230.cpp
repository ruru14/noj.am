// noj.am.2230.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

using namespace std;

int n;
ll m, ans = 0x7fffffff;
vector<int> arr;

void solve_bSearch() {
    sort(arr.begin(), arr.end());
    for (auto& i : arr) {
        auto itr = lower_bound(arr.begin(), arr.end(), i + m);
        if (itr != arr.end()) {
            ans = min(ans, *itr - (ll)i);
        }
    }

    cout << ans;
}

void solve_twoPointer() {
    sort(arr.begin(), arr.end());
    int st = 0, ed = 0;
    while (ed < n  && st < n) {
        if (arr[ed] - arr[st] >= m) {
            ll t = (ll)arr[ed] - (ll)arr[st];
            ans = min(ans, t);
            st++;
        } else ed++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        arr.push_back(foo);
    }

    solve_twoPointer();
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
