// noj.am.1991.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <map>

using namespace std;

map<char, pair<char, char>> tr;

void preorder(pair<char, char> node, char cur) {
	cout << cur;
	if (node.first != '.') preorder(tr[node.first], node.first);
	if (node.second != '.') preorder(tr[node.second], node.second);
}

void inorder(pair<char, char> node, char cur) {
	if (node.first != '.') inorder(tr[node.first], node.first);
	cout << cur;
	if (node.second != '.') inorder(tr[node.second], node.second);
}

void postorder(pair<char, char> node, char cur) {
	if (node.first != '.') postorder(tr[node.first], node.first);
	if (node.second != '.') postorder(tr[node.second], node.second);
	cout << cur;
}

int main()
{
	int n;
	cin >> n;

	while (n--) {
		char a, b, c;
		cin >> a >> b >> c;
		tr[a] = make_pair(b, c);
	}
	preorder(tr['A'], 'A');
	cout << "\n";
	inorder(tr['A'], 'A');
	cout << "\n";
	postorder(tr['A'], 'A');
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
