// noj.am.10266.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string p) {
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

void kmp(string txt, string ptn) {
    vector<int> pi = getPi(ptn);
    int j = 0, mT = txt.size(), mP = ptn.size();
    for (int i = 0; i < mT; i++) {
        while (j > 0 && txt[i] != ptn[j])
            j = pi[j - 1];
        if (txt[i] == ptn[j]) {
            if (j == mP - 1) {
                cout << "possible";
                return;
            } else {
                j++;
            }
        }
    }
    cout << "impossible";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string foo, bar;
    int n;
    cin >> n;

    for (int i = 0; i < 360000; i++) {
        foo += '0';
        bar += '0';
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (i == 0) foo[tmp] = '1';
            else bar[tmp] = '1';
        }
    }

    foo += foo;

    kmp(foo, bar);
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
