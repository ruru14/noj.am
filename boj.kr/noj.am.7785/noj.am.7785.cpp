// noj.am.7785.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    unordered_set<string> s;
    while (n--) {
        string foo, bar;
        cin >> foo >> bar;
        if (bar == "enter") s.insert(foo);
        else if (bar == "leave") s.erase(foo);
    }

    vector<string> ans;
    for (auto& i : s) ans.push_back(i);
    sort(ans.begin(), ans.end(), greater<string>());

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
