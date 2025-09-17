// noj.am.23258.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

/*
  풀이참조 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1C/solutions/23258.cpp
  핵심 아이디어는 1 + 2 + 4 + ... + 2^(C-1) = 2^C - 1 을 이용하는 것
  즉, 아무리 돌아다녀도 C 이상의 도시에 방문하지만 않으면 총 이슬의 양은 2^C 이상이 될 수 없다.
  위 식에 의해 C-1 이하의 도시는 어디든 자유롭게 다닐 수 있다.
  D를 삼차원 배열로 선언하여 각 층에 1, 2, 3, ..., i번 도시까지 방문할 수 있는 경우의 플로이드 알고리즘 결괏값을 저장한다.
  이후 문제에서 원하는 값을 받아 출력만 하면 된다.
*/

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INF)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[0][i][j];
            if (dist[0][i][j] == 0 && i != j) dist[0][i][j] = INF;
        }
    }

    // 3차원 배열 D의 첫 인덱스는 1, 2, ..., i번 도시까지 거쳐 갈 수 있을 때의 최소 거리값을 뜻함
    // 즉, D[i][s][e] 는 중간 도시의 번호가 i 이하임을 보장하면서 s 부터 e 까지 도달하는 거리의 최솟값이다.
    for (int mid = 1; mid <= n; mid++) {
        for (int st = 1; st <= n; st++) {
            for (int ed = 1; ed <= n; ed++) {
                dist[mid][st][ed] = min(dist[mid - 1][st][ed], dist[mid - 1][st][mid] + dist[mid - 1][mid][ed]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int c, from, to;
        cin >> c >> from >> to;
        if (dist[c - 1][from][to] >= INF) cout << -1 << "\n";
        else cout << dist[c - 1][from][to] << "\n";
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
