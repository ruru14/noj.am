// noj.am.2457.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int convertDate(int month, int day) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    int foo = 0;
    for (int i = 1; i < month; i++) { 
        foo += days[i];
    }
    return foo + day;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int st = convertDate(3, 1), ed = convertDate(11, 30) + 1;
    cin >> n;
    vector<pair<int, int>> arr;
    vector<bool> isSelect(n, false);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr.push_back({ convertDate(a, b) ,convertDate(c, d) });
    }

    int cur = 0, ans = 0;
    while (st < ed) {
        int curMax = 0;
        int curIdx = -1;
        for (int j = 0; j < n; j++) {
            if (isSelect[j]) continue;
            if (arr[j].first <= st) {
                if (arr[j].second > curMax) {
                    curMax = arr[j].second;
                    curIdx = j;
                }
            }
        }
        if (curIdx == -1) {
            cout << 0;
            return 0;
        }

        st = curMax;
        isSelect[curIdx] = true;
        ans++;
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
