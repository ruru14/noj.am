// noj.am10798.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> arr;
    std::string input, result = "";

    for (int i = 0; i < 5; i++) {
        std::cin >> input;
        arr.push_back(input);
    }

    for (int i = 0; i <= 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j].length() <= i) continue;
            result += arr[j].c_str()[i];
        }
    }

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
