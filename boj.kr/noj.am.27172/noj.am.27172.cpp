// noj.am.27172.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, maxCard = 0;
    cin >> n;
    vector<int> card(n, 0);
    vector<int> arr(1'000'001, 0);
    vector<int> score(1'000'001, 0);

    for (int i = 0; i < n; i++) {
        cin >> card[i];
        arr[card[i]]++;
        maxCard = max(maxCard, card[i]);
    }

    for (auto& i : card) {
        for (int j = i; j <= maxCard; j += i) {
            if (arr[j] == 0 || i == j) continue;
            if (j > i) {
                score[i]++;
                score[j]--;
            } else {
                score[i]--;
                score[j]--;
            }
        }
    }

    for (auto& i : card) cout << score[i] << " ";
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
