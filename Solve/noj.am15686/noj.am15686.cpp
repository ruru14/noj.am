// noj.am15686.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

int n, m;
std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> chicken;
int dist = INT_MAX;

int calcLength(std::pair<int, int> foo, std::pair<int, int> bar) {
    return abs(foo.first - bar.first) + abs(foo.second - bar.second);
}

void calcDist(std::vector<int> comb) {
    int newDist = 0;
    for (auto& i : house) {
        int hDist = INT_MAX;
        for (int j = 0; j < comb.size(); j++) {
            if (comb[j] == 1) {
                int tmp = calcLength(i, chicken[j]);
                if (tmp < hDist) hDist = tmp;
            }
        }
        newDist += hDist;
    }
    if (newDist < dist) dist = newDist;
}


int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            std::cin >> tmp;
            switch (tmp) {
            case 1:
                house.push_back(std::make_pair(i, j));
                break;
            case 2:
                chicken.push_back(std::make_pair(i, j));
                break;
            case 0:
                break;
            }
        }
    }

    std::vector<int> foo;
    for (int i = 0; i < chicken.size() - m; i++) foo.push_back(0);
    for (int i = 0; i < m; i++) foo.push_back(1);

    do {
        calcDist(foo);
    } while (std::next_permutation(foo.begin(), foo.end()));

    std::cout << dist;

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
