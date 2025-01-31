// noj.am.1735.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

int main()
{
    int aNum, aDen, bNum, bDen, ansNum, ansDen;
    cin >> aNum >> aDen >> bNum >> bDen;
    ansDen = aDen * bDen;
    ansNum = aNum * bDen + bNum * aDen;
    int foo = gcd(ansNum, ansDen);
    cout << ansNum / foo << " " << ansDen / foo;
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
