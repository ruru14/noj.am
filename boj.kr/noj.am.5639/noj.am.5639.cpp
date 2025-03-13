// noj.am.5639.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
    int value = 0;
    Node* lNode = nullptr;
    Node* rNode = nullptr;
};

void recur(Node* start) {
    if (start->lNode != nullptr) recur(start->lNode);
    if (start->rNode != nullptr) recur(start->rNode);
    cout << start->value << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Node* root = new Node();
    int n;
    cin >> n;
    root->value = n;

    while (cin>>n) {
        Node* tmp = root;
        Node* newNode = new Node();
        newNode->value = n;
        bool flag = true;
        while (flag) {
            if (tmp->value < n) {
                if (tmp->rNode == nullptr) {
                    tmp->rNode = newNode;
                    flag = false;
                } else {
                    tmp = tmp->rNode;
                }
            } else {
                if (tmp->lNode == nullptr) {
                    tmp->lNode = newNode;
                    flag = false;
                } else {
                    tmp = tmp->lNode;
                }
            }
        }
    }

    recur(root);

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
