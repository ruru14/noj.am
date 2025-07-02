// noj.am.1461.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> plus, minus;
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        if (foo > 0) plus.push_back(foo);
        else minus.push_back(foo);
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    int foo = plus.size() == 0 ? 0 : abs(plus[0]);
    int bar = minus.size() == 0 ? 0 : abs(minus[0]);
    int startP = 0, startM = 0;

    if (foo > bar) {
        ans += plus[0];
        startP = m;
    } else {
        ans += abs(minus[0]);
        startM = m;
    }

    for (int i = startP; i < plus.size(); i += m) ans += plus[i] * 2;
    for (int i = startM; i < minus.size(); i += m) ans += abs(minus[i] * 2);

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
