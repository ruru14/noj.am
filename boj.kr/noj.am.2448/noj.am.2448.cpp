// noj.am.2448.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> map;

void recur(int x, int y, int n) {
    if (n == 3) {
        map[x][y] = '*';
        map[x - 1][y+1] = '*';
        map[x + 1][y+1] = '*';
        for (int i = 0; i < 5; i++) map[x - 2 + i][y + 2] = '*';
        return;
    }

    recur(x, y, n / 2);
    recur(x - (n / 2), y + (n / 2), n / 2);
    recur(x + (n / 2), y + (n / 2), n / 2);
}

int main()
{
    int n;
    cin >> n;
    map.assign(2 * n, vector<char>(n, ' '));

    recur(n-1, 0, n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 2 * n - 1; x++) cout << map[x][y];
        cout << "\n";
    }
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
