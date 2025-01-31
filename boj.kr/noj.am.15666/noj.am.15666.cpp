// noj.am.15666.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<int> arr;
set<vector<int>> answer;

void func(vector<int> seq, int cur, int idx, int dim) {
    if (dim == m) {
        answer.insert(seq);
        return;
    }

    int foo = 0;
    for (auto& i : arr) {
        if (i < cur) continue;
        vector<int> bar(seq);
        bar.push_back(i);
        func(bar, i, idx + (foo++), dim + 1);
    }

}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        arr.insert(foo);
    }

    vector<int> foo;
    func(foo, 0, 0, 0);

    for (auto& i : answer) {
        for (auto& j : i) cout << j << " ";
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
