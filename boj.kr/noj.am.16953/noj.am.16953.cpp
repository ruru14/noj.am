// noj.am.16953.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

long long answer = -1;

void function(long long a, long long b, long long cnt) {
    if (a > b) return;
    if (a == b) {
        if (answer == -1 || answer > cnt) answer = cnt;
        return;
    }
    function(a * 2, b, cnt + 1);
    function(a * 10 + 1, b, cnt + 1);

}

int main()
{
    long long a, b;
    cin >> a >> b;
    function(a, b, 0);
    cout << answer + (answer == -1 ? 0 : 1);
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
