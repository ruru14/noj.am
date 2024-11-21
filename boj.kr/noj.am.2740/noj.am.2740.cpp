// noj.am2740.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    int k;
    int foo;
    vector<vector<int>> matA, matB, answer;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            cin >> foo;
            tmp.push_back(foo);
        }
        matA.push_back(tmp);
    }

    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < k; j++) {
            cin >> foo;
            tmp.push_back(foo);
        }
        matB.push_back(tmp);
    }

    answer.assign(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int tmp = 0;
            for (int l = 0; l < m; l++) {
                answer[i][j] += matA[i][l] * matB[l][j];
            }
        }
    }

    for (auto& i : answer) {
        for (auto& j : i) {
            cout << j << " ";
        }
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
