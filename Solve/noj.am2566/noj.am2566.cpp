// noj.am2566.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    int num, maxVal = -1;
    int maxIdx_x;
    int maxIdx_y;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> num;
            if (num > maxVal) {
                maxVal = num;
                maxIdx_x = j;
                maxIdx_y = i;
            }
        }
    }

    std::cout << maxVal << "\n" << maxIdx_y + 1 << " " << maxIdx_x + 1;
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
