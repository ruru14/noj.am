// noj.am.30804.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, max = 0;
    cin >> n;

    map<int, int> foo;
    deque<int> bar;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        bar.push_back(tmp);
        foo[tmp]++;
        while (foo.size() > 2) {
            int baz = bar.front();
            foo[baz]--;
            if (foo[baz] == 0) foo.erase(baz);
            bar.pop_front();
        }
        if (max < bar.size()) max = bar.size();
    }

    cout << max;
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
