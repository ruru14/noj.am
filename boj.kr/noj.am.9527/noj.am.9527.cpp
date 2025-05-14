// noj.am.9527.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

long long cntOne(long long n) {
    long long bit = log2(n);
    long long cnt = 0;

    for (int i = 0; i <= bit; i++) {
        long long cycle = 1LL << (i + 1);
        long long pos = 1LL << i;

        cnt += (n / cycle)*pos;

        long long remain = n % cycle;
        if (remain >= pos)
            cnt += remain - pos + 1;
    }

    return cnt;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << cntOne(b) - cntOne(a - 1);
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
