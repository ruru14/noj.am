// noj.am.28702.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string foo;
    int nxt = 0;

    for (int i = 0; i < 3; i++) {
        cin >> foo;
        if (foo[0] >= '0' && foo[0] <= '9') {
            nxt = stoi(foo) + (3 - i);
        }
    }

    if (nxt % 3 == 0 && nxt % 5 == 0) cout << "FizzBuzz";
    else if (nxt % 3 == 0 && nxt % 5 != 0) cout << "Fizz";
    else if (nxt % 3 != 0 && nxt % 5 == 0) cout << "Buzz";
    else cout << nxt;
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
