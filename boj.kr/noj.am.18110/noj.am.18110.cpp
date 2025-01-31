// noj.am.18110.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> sol(n);

    if (n == 0) {
        cout << 0;
        return 0;
    }

    while (n--) {
        cin >> sol[n];
    }

    sort(sol.begin(), sol.end());
    int ex = round(sol.size() * 0.15);
    
    for (int i = ex; i < sol.size() - ex; i++) {
        sum += sol[i];
    }

    cout << round((float)sum / (sol.size() - ex * 2));
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
