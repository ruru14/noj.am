// noj.am.1644.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> isPrime(4'000'001, true);

vector<int> getPrime(int MAX) {
    vector<int> prime;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(MAX); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            } 
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
    return prime;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, answer = 0;
    cin >> n;
    vector<int> foo = getPrime(n);

    if (foo.empty()) {
        cout << 0;
        return 0;
    }

    int start = 0, end = 0;
    int sum = foo[start];

    while (start <= end && end < foo.size()) {
        if (sum == n) {
            answer++;
            end++;
            if (end < foo.size()) sum += foo[end];
        } else if (sum < n) {
            end++;
            if (end < foo.size()) sum += foo[end];
        } else {
            sum -= foo[start];
            start++;
        }
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
