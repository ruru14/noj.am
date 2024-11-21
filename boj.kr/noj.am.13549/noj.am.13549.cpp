#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<int> dist;

void bfs() {
    deque<int> deque;
    int curPos;
    dist[n] = 0;
    deque.push_front(n);

    while (!deque.empty()) {
        curPos = deque.front();
        deque.pop_front();

        if (curPos == k) {
            cout << dist[curPos];
            break;
        }

        if (curPos * 2 < 200000 && dist[curPos * 2] > dist[curPos]) {
            dist[curPos * 2] = dist[curPos];
            deque.push_front(curPos * 2);
        }

        if (curPos - 1 >= 0 && dist[curPos - 1] > dist[curPos] + 1) {
            dist[curPos - 1] = dist[curPos] + 1;
            deque.push_back(curPos - 1);
        }

        if (curPos + 1 < 200000 && dist[curPos + 1] > dist[curPos] + 1) {
            dist[curPos + 1] = dist[curPos] + 1;
            deque.push_back(curPos + 1);
        }
    }

}

int main() {
    cin >> n >> k;
    dist.assign(200001, 21000000);
    bfs();

}