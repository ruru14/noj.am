#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int n, m;
int adj[101][101];
int dist[101][101];
int bacon[101];

int main() {
    cin >> n >> m;
    int min_bacon = 50000000;
    int answer = -1;
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = 50000000;
        }
    }*/

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        bacon[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = 50000000;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            bacon[i] += dist[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (min_bacon > bacon[i]) {
            min_bacon = bacon[i];
            answer = i;
        }
    }

    cout << answer;
}