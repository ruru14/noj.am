// noj.am.1268.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> cls(n + 1, vector<int>(6));
    vector<set<int>> pres(n + 1);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < 6; j++) cin >> cls[i][j];
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1 && j != i; j++) {
            for (int k = 1; k < 6; k++) {
                if (cls[i][k] == cls[j][k]) {
                    pres[i].insert(j);
                    pres[j].insert(i);
                    break;
                }
            }
        }
    }
    
    int max = 0, maxP = 1;
    for (int i = 1; i < n + 1; i++) {
        if (max < pres[i].size()) {
            max = pres[i].size();
            maxP = i;
        }
    }

    cout << maxP;

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
