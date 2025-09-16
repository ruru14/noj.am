// noj.am.1927.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> heap(100'001, -1);
int sz = 0;

void push(int val) {
    heap[++sz] = val;
    int curParent = sz / 2;
    int curChild = sz;
    while (heap[curParent] > heap[curChild]) {
        swap(heap[curParent], heap[curChild]);
        curChild = curParent;
        curParent = curParent / 2;
    }
}

int top() {
    return heap[1];
}

void pop() {
    if (sz == 0) return;
    swap(heap[1], heap[sz]);
    heap[sz--] = -1;
    int parent = 1, lChild = 2, rChild = 3;
    while (1) {
        if (heap[lChild] == -1) {
            break;
        }
        if (heap[rChild] == -1) {
            if (heap[parent] > heap[lChild]) {
                swap(heap[parent], heap[lChild]);
            }
            break;
        }
        if (heap[parent] <= heap[lChild] && heap[parent] <= heap[rChild]) {
            break;
        }
        if (heap[lChild] >= heap[rChild]) {
            swap(heap[parent], heap[rChild]);
            parent = rChild;
            lChild = parent * 2;
            rChild = parent * 2 + 1;
        } else {
            swap(heap[parent], heap[lChild]);
            parent = lChild;
            lChild = parent * 2;
            rChild = parent * 2 + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> ans;
    cin >> n;
    heap[0] = -1;
    while (n--) {
        int foo;
        cin >> foo;
        if (foo == 0) {
            int t = top();
            if (t == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(t);
                pop();
            }
        } else {
            push(foo);
        }
    }

    for (auto& i : ans) cout << i << "\n";
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
