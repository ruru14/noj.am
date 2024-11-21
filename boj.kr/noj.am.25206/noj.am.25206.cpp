// noj.am25206.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main() {
    std::string name, grade;
    float credit;
    float totalCredit = 0.0f;
    float score = 0.0f;

    for (int i = 0; i < 20; i++) {
        std::cin >> name >> credit >> grade;
        if (grade == "P") continue;
        totalCredit += credit;
        if (grade == "A+") {
            score += 4.5f * credit;
        } else if (grade == "A0") {
            score += 4.0f * credit;
        } else if (grade == "B+") {
            score += 3.5f * credit;
        } else if (grade == "B0") {
            score += 3.0f * credit;
        } else if (grade == "C+") {
            score += 2.5f * credit;
        } else if (grade == "C0") {
            score += 2.0f * credit;
        } else if (grade == "D+") {
            score += 1.5f * credit;
        } else if (grade == "D0") {
            score += 1.0f * credit;
        } else if (grade == "F") {
            score += 0.0f * credit;
        }
    }
    std::cout << score / totalCredit;
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
