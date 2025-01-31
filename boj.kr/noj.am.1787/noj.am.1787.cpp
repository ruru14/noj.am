// noj.am.1787.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long answer = 0;
    string s, foo;
    cin >> n >> s;
    vector<int> seq(s.size(), 0), pi(s.size(), 0);

    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;

        int k = i + 1;
        if (pi[k - 1] - 1 >= 0)
            seq[i] = pi[pi[k - 1] - 1] > 0 ? seq[pi[k - 1] - 1] : pi[k - 1];
        if (!seq[i]) continue;
        if (i + 1 - seq[i] >= seq[i])
            answer += i + 1 - seq[i];
    }

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
