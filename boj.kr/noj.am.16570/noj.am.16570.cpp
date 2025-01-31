// noj.am.16570.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(vector<int> arr) {
    vector<int> pi(arr.size(), 0);

    for (int i = 1, j = 0; i < arr.size(); i++) {
        while (j > 0 && arr[i] != arr[j])
            j = pi[j - 1];
        if (arr[i] == arr[j])
            pi[i] = ++j;
    }

    return pi;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, max = 0, meth = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    reverse(arr.begin(), arr.end());

    vector<int> pi = getPi(arr);
    for (auto& i : pi) {

        if (i == max) meth++;
        if (i > max) {
            meth = 1;
            max = i;
        }
    }

    if (max > 0) cout << max << " " << meth;
    else cout << -1;
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
