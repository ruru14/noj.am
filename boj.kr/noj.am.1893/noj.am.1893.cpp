// noj.am.1893.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;

	while (tc--) {
		string a, w, s;
        vector<int> answer;
		map<char, int> dict;
		map<int, char> r_dict;
		cin >> a >> w >> s;
		for (int i = 0; i < a.size(); i++) {
			dict[a[i]] = i;
			r_dict[i] = a[i];
		}

        for (int i = 0; i < a.size(); i++) {
            string foo;
            for (auto& j : w) {
                int idx = dict[j] + i;
                if (idx >= a.size()) idx -= a.size();
                foo += r_dict[idx];
            }
            vector<int> bar = kmp(s, foo);
            if (bar.size() == 1) answer.push_back(i);
        }

        if (answer.size() == 0) {
            cout << "no solution\n";
        } else if (answer.size() == 1) {
            cout << "unique: " << answer[0] << "\n";
        } else {
            cout << "ambiguous: ";
            for (auto& i : answer) cout << i << " ";
            cout << "\n";
        }
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
