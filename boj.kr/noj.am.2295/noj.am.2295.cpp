// noj.am.2295.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr, two;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        arr.push_back(foo);
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }

    sort(two.begin(), two.end());
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
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
