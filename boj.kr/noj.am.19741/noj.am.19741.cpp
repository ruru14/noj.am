// noj.am.19741.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> countAllDivisors(int max_num) {
    vector<int> divisorCount(max_num + 1, 0);

    for (int i = 1; i <= max_num; i++) {
        for (int j = i; j <= max_num; j += i) {
            divisorCount[j]++;
        }
    }

    return divisorCount;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> foo = countAllDivisors(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (foo[i * n + j] <= k) cout << "*";
            else cout << ".";
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
