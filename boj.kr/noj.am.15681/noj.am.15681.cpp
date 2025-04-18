// noj.am.15681.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int parent = -1;
    vector<int> child;
};

vector<vector<int>> tree;
vector<Node> nodeInfo;
vector<int> query;

void makeTree(int curNode, int parent) {
    for (auto& i : tree[curNode]) {
        if (i != parent) {
            nodeInfo[curNode].child.push_back(i);
            nodeInfo[i].parent = curNode;
            makeTree(i, curNode);
        }
    }
}

void countSubtreeNode(int curNode) {
    query[curNode] = 1;
    for (auto& i : nodeInfo[curNode].child) {
        countSubtreeNode(i);
        query[curNode] += query[i];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, q;
    cin >> n >> r >> q;
    tree.assign(n + 1, vector<int>());
    nodeInfo.assign(n + 1, Node());
    query.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    makeTree(r, -1);
    countSubtreeNode(r);
    
    for (int i = 0; i < q; i++) {
        int foo;
        cin >> foo;
        cout << query[foo] << "\n";
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
