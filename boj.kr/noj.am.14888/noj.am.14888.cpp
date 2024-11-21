// noj.am14888.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>;

int main() {
    int n;
    std::vector<int> nums;
    std::vector<char> opers;
    std::set<int> answer;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        nums.push_back(tmp);
    }
    for (int i = 0; i < 4; i++) {
        int tmp = 0;
        std::cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            switch (i) {
            case 0:
                opers.push_back('+');
                break;
            case 1:
                opers.push_back('-');
                break;
            case 2:
                opers.push_back('*');
                break;
            case 3:
                opers.push_back('d');
                break;
            }
        }
    }

    std::sort(opers.begin(), opers.end());

    do {
        int foo = nums[0];
        for (int i = 1; i < n; i++) {
            switch (opers[i - 1]) {
            case '+':
                foo = foo + nums[i];
                break;
            case '-':
                foo = foo - nums[i];
                break;
            case '*':
                foo = foo * nums[i];
                break;
            case 'd':
                foo = foo / nums[i];
                break;
            }
        }
        answer.insert(foo);
    } while (std::next_permutation(opers.begin(), opers.end()));

    std::cout << *answer.rbegin() << "\n" << *answer.begin();

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
