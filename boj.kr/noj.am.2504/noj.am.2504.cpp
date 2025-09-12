// noj.am.2504.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    string foo;
    cin >> foo;
    stack<pair<char,int>> s1;
    vector<int> arr(foo.size(), 0);
    for (int i = 0; i < foo.size(); i++) {
        if (foo[i] == '(' || foo[i] == '[') s1.push({ foo[i],i });
        else {
            if (s1.empty()) {
                cout << 0;
                return 0;
            }
            auto cur = s1.top();
            s1.pop();
            if (foo[i] == ')') {
                if (cur.first != '(') {
                    cout << 0;
                    return 0;
                }
                int tmp = 0;
                for (int j = cur.second; j <= i; j++) {
                    tmp += arr[j];
                    arr[j] = 0;
                }
                if (tmp == 0) arr[i] = 2;
                else arr[i] = tmp * 2;
            } else {
                if (cur.first != '[') {
                    cout << 0;
                    return 0;
                }
                int tmp = 0;
                for (int j = cur.second; j <= i; j++) {
                    tmp += arr[j];
                    arr[j] = 0;
                }
                if (tmp == 0) arr[i] = 3;
                else arr[i] = tmp * 3;
            }
        }
    }

    if (s1.empty()) {
        for (auto& i : arr) ans += i;
    }
    cout << ans;
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
