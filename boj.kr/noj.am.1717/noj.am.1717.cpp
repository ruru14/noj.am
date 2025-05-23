// noj.am.1717.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int Find(int n) {
        if (parent[n] != n) parent[n] = Find(parent[n]);
        return parent[n];
    }

    void Union(int a, int b) {
        parent[Find(a)] = Find(b);
    }

    bool IsSameSet(int a, int b) {
        return Find(a) == Find(b);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    DisjointSet s(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            s.Union(b, c);
        } else {
            if (s.IsSameSet(b, c)) cout << "YES\n";
            else cout << "NO\n";
        }
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
