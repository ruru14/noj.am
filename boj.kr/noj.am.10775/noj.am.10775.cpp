// noj.am.10775.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    int Find(int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);

        return parent[x];
    }

    void Union(int a, int b) {
        parent[Find(a)] = Find(b);
    }

};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int g, p, ans = 0;
    cin >> g >> p;
    vector<int> plain(p);
    DisjointSet s(g);
    for (int i = 0; i < p; i++) cin >> plain[i];

    for (auto& i : plain) {
        int foo = s.Find(i);
        if (foo == 0) break;
        s.Union(i, foo - 1);
        ans++;
    }

    cout << ans;
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
