// noj.am2480.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
    int a, b, c, result = 0;
    std::cin >> a >> b >> c;

    if (a == b && a == c) {
        result += 10000 + a * 1000;
        std::cout << result;
        return 0;
    }

    if (a == b) {
        result += 1000 + a * 100;
        std::cout << result;
        return 0;
    } else if (b == c) {
        result += 1000 + b * 100;
        std::cout << result;
        return 0;
    } else if (a == c) {
        result += 1000 + a * 100;
        std::cout << result;
        return 0;
    }

    result += (a > b && a > c ? a : b > a && b > c ? b : c) * 100;
    std::cout << result;
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
