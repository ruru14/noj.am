// noj.am.1715.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, answer = 0;
    cin >> n;
    priority_queue<int> q;

    while (n--) {
        int tmp;
        cin >> tmp;
        q.push(-tmp);
    }

    while (q.size() > 1) {
        int foo = q.top(); q.pop();
        int bar = q.top(); q.pop();
        answer += (foo + bar);
        q.push(foo + bar);
    }

    cout << -answer;
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
