// noj.am.2751.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void merge_sort(int st, int ed) {
    if (ed - st <= 1) return;
    int mid = st + (ed - st) / 2;

    merge_sort(st, mid);
    merge_sort(mid, ed);

    vector<int> tmp(ed - st);
    int stA = st, stB = mid, idx = 0;
    while (stA < mid && stB < ed) {
        if (arr[stA] <= arr[stB]) tmp[idx++] = arr[stA++];
        else tmp[idx++] = arr[stB++];
    }

    while (stA < mid) tmp[idx++] = arr[stA++];
    while (stB < ed) tmp[idx++] = arr[stB++];

    for (int i = 0; i < idx; i++) arr[st + i] = tmp[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int foo;
        cin >> foo;
        arr.push_back(foo);
    }

    merge_sort(0, n);

    for (auto& i : arr) cout << i << "\n";
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
