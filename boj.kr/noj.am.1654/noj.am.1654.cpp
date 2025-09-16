// noj.am.1654.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

using namespace std;

ll getCable(vector<int> cable, ll size) {
    ll result = 0;
    for (auto& i : cable) result += i / size;
    return result;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int k, n;
    ll st = 1, ed = 0x7fffffff;
    cin >> k >> n;
    vector<int> cable;
    cable.reserve(k);
    for (int i = 0; i < k; i++) {
        ll foo;
        cin >> foo;
        cable.push_back(foo);
    }

    ll mid = st + (ed - st) / 2;
    while (st < ed) {
        mid = st + (1 + ed - st) / 2;
        if (getCable(cable, mid) < n) ed = mid - 1;
        else st = mid;
    }
    cout << st;
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
