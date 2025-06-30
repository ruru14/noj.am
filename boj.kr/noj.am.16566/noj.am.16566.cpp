// noj.am.16566.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> card(m);
    vector<bool> used(m, false);
    for (int i = 0; i < m; i++) cin >> card[i];
    sort(card.begin(), card.end());

    for (int i = 0; i < k; i++) {
        int foo;
        cin >> foo;
        auto itr = upper_bound(card.begin(), card.end(), foo);
        while (used[itr - card.begin()]) itr++;
        cout << *itr << "\n";
        used[itr - card.begin()] = true;
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
