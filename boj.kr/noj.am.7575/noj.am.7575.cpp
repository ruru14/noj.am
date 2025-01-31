// noj.am.7575.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(vector<int> p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

bool kmp(vector<int> code, vector<int> ptn) {
    vector<int> pi = getPi(ptn);
    int j = 0, mT = code.size(), mP = ptn.size();
    for (int i = 0; i < mT; i++) {
        while (j > 0 && code[i] != ptn[j])
            j = pi[j - 1];
        if (code[i] == ptn[j]) {
            if (j == mP - 1) {
                return true;
            } else {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> code;
    vector<vector<int>> virus;
    vector<vector<int>> r_virus;

    while (n--) {
        int m;
        vector<int> foo;
        cin >> m;
        while (m--) {
            int c;
            cin >> c;
            foo.push_back(c);
        }
        code.push_back(foo);
    }

    vector<int> tmp(*code.begin());
    code.erase(code.begin());

    for (int i = 0; i <= tmp.size() - k; i++) {
        vector<int> foo(k), bar(k);
        for (int j = i; j < i + k; j++) {
            foo[j - i] = tmp[j];
            bar[(k - 1) - (j - i)] = tmp[j];
        }
        virus.push_back(foo);
        r_virus.push_back(bar);
    }

    for (int i = 0; i < virus.size(); i++) {
        bool flag = true;
        for (auto& j : code) {
            if (!(kmp(j, virus[i]) || kmp(j, r_virus[i]))) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
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
