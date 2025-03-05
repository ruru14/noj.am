// noj.am.2096.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define MAX 9'999'999

int main()
{
    int n;
    int arr[3];
    int max_arr[3];
    int min_arr[3];
    int max_tmp[3];
    int min_tmp[3];
    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> max_arr[i];
        min_arr[i] = max_arr[i];
        max_tmp[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int i = 0; i < 3; i++) cin >> arr[i];

        max_tmp[0] = max({
            max_arr[0] + arr[0],
            max_arr[1] + arr[0]
            });
        max_tmp[1] = max({
            max_arr[0] + arr[1],
            max_arr[1] + arr[1],
            max_arr[2] + arr[1]
            });
        max_tmp[2] = max({
            max_arr[1] + arr[2],
            max_arr[2] + arr[2]
            });

        min_tmp[0] = min({
            min_arr[0] + arr[0],
            min_arr[1] + arr[0]
            });
        min_tmp[1] = min({
            min_arr[0] + arr[1],
            min_arr[1] + arr[1],
            min_arr[2] + arr[1]
            });
        min_tmp[2] = min({
            min_arr[1] + arr[2],
            min_arr[2] + arr[2]
            });

        for (int i = 0; i < 3; i++) {
            max_arr[i] = max_tmp[i];
            min_arr[i] = min_tmp[i];
        }
    }

    cout << max({ max_arr[0],max_arr[1],max_arr[2] });
    cout << " ";
    cout << min({ min_arr[0],min_arr[1],min_arr[2] });

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
