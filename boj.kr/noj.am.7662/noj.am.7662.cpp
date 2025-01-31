// noj.am.7662.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        multiset<int> foo;

        while (n--) {
            char ord;
            int num;
            cin >> ord >> num;
            
            if (ord == 'I') {
                foo.insert(num);
            } else {
                if (foo.empty()) continue;
                if (num == 1) foo.erase(--foo.end());
                else foo.erase(foo.begin());
            }
        }

        if (foo.empty()) cout << "EMPTY\n";
        else cout << *(--foo.end()) << " " << *foo.begin() << "\n";
    }
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
