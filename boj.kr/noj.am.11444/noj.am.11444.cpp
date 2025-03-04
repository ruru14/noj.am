// noj.am.11444.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define MOD 1'000'000'007

vector<vector<long long>> matmul(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
	vector<vector<long long>> ans(2, vector<long long>(2, 0));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				ans[i][j] = ((ans[i][j] % MOD) % MOD + (a[i][k] % MOD * b[k][j] % MOD) % MOD) % MOD;
	
	return ans;
}

int main()
{
	long long n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	bitset<64> bin(n-1);
	vector<int> binarr;
	vector<vector<vector<long long>>> mat_pow;
	vector<vector<long long>> mat_ans({ {1, 0}, {0, 1} });

	mat_pow.push_back({ {1, 1}, {1, 0} });

	for (int i = 0; i < 64; i++) {
		auto tmp = *(mat_pow.end() - 1);
		mat_pow.push_back(matmul(tmp, tmp));
	}

	for (int i = 0; i < 64; i++) {
		if (bin[i] == 1) {
			mat_ans = matmul(mat_ans, mat_pow[i]);
		}
	}

	cout << mat_ans[0][0];
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
