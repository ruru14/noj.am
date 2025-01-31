// noj.am.1097.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPi(string ptn) {
    vector<int> pi(ptn.size(), 0);
    int j = 0;
    for (int i = 1; i < ptn.size(); i++) {
        while (j > 0 && ptn[i] != ptn[j])
            j = pi[j - 1];
        if (ptn[i] == ptn[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string txt, string ptn) {
    vector<int> pi = getPi(ptn);
    vector<int> idx;
    int j = 0, mT = txt.size(), mP = ptn.size();
    for (int i = 0; i < mT; i++) {
        while (j > 0 && txt[i] != ptn[j])
            j = pi[j - 1];
        if (txt[i] == ptn[j]) {
            if (j == mP - 1) {
                idx.push_back(i - j - 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return idx;
}

int main()
{
    int n, k, answer = 0;
    vector<string> arr;
    vector<int> seq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        seq.push_back(i);
        string tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> k;

    do {
        string foo, bar;
        for (auto& i : seq) foo += arr[i];
        bar = foo;
        foo += foo;
        foo.pop_back();
        vector<int> baz = kmp(foo, bar);
        if (baz.size() == k) answer++;

    } while (next_permutation(seq.begin(), seq.end()));

    cout << answer;
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
