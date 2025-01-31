// noj.am.1343.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string board, answer = "";
    cin >> board;
    
    int cnt = 0;
    for (auto& i : board) {
        if (i == '.') {
            if (cnt % 2 == 1) {
                cout << -1;
                return 0;
            } else {
                while (cnt >= 4) {
                    cnt -= 4;
                    answer += "AAAA";
                }
                while (cnt >= 2) {
                    cnt -= 2;
                    answer += "BB";
                }
            }
            answer += ".";
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt > 0) {
        if (cnt % 2 == 1) {
            cout << -1;
            return 0;
        } else {
            while (cnt >= 4) {
                cnt -= 4;
                answer += "AAAA";
            }
            while (cnt >= 2) {
                cnt -= 2;
                answer += "BB";
            }
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
