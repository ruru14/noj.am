// noj.am.14425.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    set<string> s;
    int answer = 0;
    cin >> n >> m;


    while (n--) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    while (m--) {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) answer++;
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
