// noj.am10830.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mulMatrix(vector<vector<long long>> a, vector<vector<long long>> b, int size) {
    vector<vector<long long>> ans(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            long long tmp = 0;
            for (int k = 0; k < size; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= 1000;
        }
    }
    return ans;
}

int main() {
    long long n, b;
    vector<vector<long long>> matrix;
    vector<vector<long long>> answer;
    cin >> n >> b;
    matrix.assign(n, vector<long long>(n, 0));
    answer.assign(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (i == j) answer[i][j] = 1;
        }
    }

    while (b > 0) {
        if (b % 2 == 1) {
            answer = mulMatrix(answer, matrix, n);;
        }
        matrix = mulMatrix(matrix, matrix, n);
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
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
