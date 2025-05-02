// noj.am.2143.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long t, n, m;
    cin >> t >> n;
    vector<long long> arrA(n, 0);
    for (int i = 0; i < n; i++) cin >> arrA[i];
    cin >> m;
    vector<long long> arrB(m, 0);
    for (int i = 0; i < m; i++) cin >> arrB[i];


    vector<long long> sumA, sumB;

    for (int i = 0; i < n; i++) {
        long long sum = arrA[i];
        sumA.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += arrA[j];
            sumA.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        long long sum = arrB[i];
        sumB.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += arrB[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    long long ans = 0;
    int ptrA = 0, ptrB = sumB.size() - 1;

    while (ptrA < sumA.size() && ptrB >= 0) {
        long long curSum = sumA[ptrA] + sumB[ptrB];
        if (curSum == t) {
            long long tmpA = 1, tmpB = 1;
            while (ptrA + 1 < sumA.size() && sumA[ptrA] == sumA[ptrA + 1]) {
                ptrA++;
                tmpA++;
            }

            while (ptrB - 1 >= 0 && sumB[ptrB] == sumB[ptrB - 1]) {
                ptrB--;
                tmpB++;
            }
            ans += (tmpA * tmpB);
            ptrA++;
            ptrB--;
        } else if (curSum < t) {
            ptrA++;
        } else {
            ptrB--;
        }
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
