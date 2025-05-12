// noj.am.2473.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define MAX 3'333'333'333

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long long sum = abs(MAX);
    cin >> n;
    vector<long long> arr(n, 0);
    vector<int> ans(3);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int start, end, mid;
    for (int i = 0; i < n; i++) {
        mid = i;
        start = 0, end = n - 1;
        while (start < end) {
            if (start == mid) {
                start++;
                continue;
            }
            if (end == mid) {
                end--;
                continue;
            }
            long long foo = arr[start] + arr[mid] + arr[end];
            if (abs(foo) < abs(sum)) {
                sum = foo;
                ans[0] = arr[start];
                ans[1] = arr[mid];
                ans[2] = arr[end];
            }
            if (foo > 0) {
                end--;
            } else {
                start++;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    for (auto& i : ans) cout << i << " ";
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
