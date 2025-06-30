// noj.am.12850.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define MOD 1'000'000'007
#define LL long long

using namespace std;

vector<vector<LL>> graph({
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,0,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,0,1,0,1,1,0},
    {0,0,1,1,1,0,0,1},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,1,1,0}
    });

vector<vector<LL>> matrixMulti(vector<vector<LL>>& a, vector<vector<LL>> b) {
    vector<vector<LL>> result(8, vector<LL>(8, 0));
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            LL sum = 0;
            for (int k = 0; k < 8; k++) {
                sum = (sum + a[i][k] * b[k][j]) % MOD;
            }
            result[i][j] = sum % MOD;
        }
    }
    return result;
}

vector<vector<LL>> matrixPow(vector<vector<LL>> A, LL D) {
    vector<vector<LL>> result(8, vector<LL>(8, 0));

    for (int i = 0; i < 8; i++) {
        result[i][i] = 1;
    }

    while (D > 0) {
        if (D & 1) {
            result = matrixMulti(result, A);
        }
        A = matrixMulti(A, A);
        D >>= 1;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<vector<LL>> foo = matrixPow(graph, n);
    cout << foo[0][0];
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
