// noj.am.11585.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

vector<int> getPi(string ptn) {
    vector<int> pi(ptn.size(), 0);
    int m = 0;

    for (int i = 1; i < ptn.size(); i++) {
        while (m > 0 && ptn[m] != ptn[i])
            m = pi[m - 1];
        if (ptn[m] == ptn[i])
            pi[i] = ++m;
    }

    return pi;
}

vector<int> kmp(string txt, string ptn) {
    vector<int> pi = getPi(ptn);
    vector<int> idx;
    int m = 0;

    for (int i = 0; i < txt.size(); i++) {
        while (m > 0 && txt[i] != ptn[m])
            m = pi[m - 1];
        if (txt[i] == ptn[m]) {
            if (m == ptn.size() - 1) {
                idx.push_back(i - m + 1);
                m = pi[m];
            } else {
                m++;
            }
        }
    }

    return idx;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    string foo, bar;
    int n;
    cin >> n;
  
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            if (i == 0) foo += t;
            else bar += t;
        }
    }

    foo += foo;
    foo.pop_back();
    vector<int> idx = kmp(foo, bar);
    int baz = gcd(idx.size(), n);

    int a = idx.size() / baz, b = n / baz;
    if (a >= b) cout << "1/1";
    else cout << a << "/" << b;

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
