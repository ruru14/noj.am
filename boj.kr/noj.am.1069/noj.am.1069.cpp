// noj.am.1069.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    double x, y, d, t;
    cin >> x >> y >> d >> t;
    double dist = sqrt(x * x + y * y);
    int jump = dist / d;
    double ans = dist;
    ans = min(ans, t + abs(dist - d));

    int i = 2;
    while (true) {
        if (i * d > dist) {
            ans = min(ans, i * t);
            break;
        }
        ans = min(ans, i * t + abs(dist - i * d));
        i++;
    }

    cout.precision(13);
    cout << fixed;
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
