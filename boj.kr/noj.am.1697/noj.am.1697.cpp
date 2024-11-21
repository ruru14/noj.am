#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>

using namespace std;

vector<int> map;
int ds[] = { 1, -1, 2 };

void foo(int n, int k, int layer) {
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nextNum = current.first;
            if (i == 2) nextNum *= ds[i];
            else nextNum += ds[i];

            if (nextNum == k) {
                cout << current.second + 1;
                return;
            }
            if (nextNum > 200000 || nextNum < 0) continue;
            if (map[nextNum] > current.second + 1) {
                map[nextNum] = current.second + 1;
                q.push(make_pair(nextNum, current.second + 1));
            }
        }
    }
}

int main() {
    int n, k;
    map.assign(200001, INT_MAX);
    cin >> n >> k;
    if (n == k) cout << "0";
    else foo(n, k, 0);
}