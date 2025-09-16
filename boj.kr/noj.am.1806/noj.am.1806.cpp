// noj.am.1806.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        arr.push_back(foo);
    }

    int st = 0, ed = 0;
    int len = 100'001;
    int sum = 0;

    while (ed < n) {
        sum += arr[ed];
        while (sum >= s) {
            len = min(len, ed - st + 1);
            sum -= arr[st];
            st++;
        }
        ed++;
    }
    
    if (len == 100'001) cout << 0;
    else cout << len;
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
