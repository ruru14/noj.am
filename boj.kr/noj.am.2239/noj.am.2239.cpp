// noj.am.2239.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int sudoku[9][9];
bool stopFlag = false;

void printSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cout << sudoku[i][j];
		cout << "\n";
	}
}

int getAvailNum(int row, int col) {
	int result = 0x1FF;

	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] > 0) result &= ~(1 << (sudoku[row][i] - 1));
		if (sudoku[i][col] > 0) result &= ~(1 << (sudoku[i][col] - 1));
	}
	int startRow = (row / 3) * 3;
	int startCol = (col / 3) * 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[startRow + i][startCol + j] > 0)
				result &= ~(1 << (sudoku[startRow + i][startCol + j] - 1));

	return result;
}

void backtrack() {
	int emR = -1, emC = -1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				emR = i;
				emC = j;
				break;
			}
		}
		if (emR != -1) break;
	}

	if (emR == -1) {
		printSudoku();
		stopFlag = true;
	}

	if (stopFlag) return;
	int avail = getAvailNum(emR, emC);
	for (int i = 0; i < 9; i++) {
		if (avail & (1 << i)) {
			sudoku[emR][emC] = i + 1;
			backtrack();
			sudoku[emR][emC] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		string foo;
		cin >> foo;
		for (int j = 0; j < 9; j++) sudoku[i][j] = foo[j] - '0';
	}

	backtrack();
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
