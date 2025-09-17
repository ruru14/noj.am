// noj.am.23258.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

/*
  Ǯ������ : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1C/solutions/23258.cpp
  �ٽ� ���̵��� 1 + 2 + 4 + ... + 2^(C-1) = 2^C - 1 �� �̿��ϴ� ��
  ��, �ƹ��� ���ƴٳ൵ C �̻��� ���ÿ� �湮������ ������ �� �̽��� ���� 2^C �̻��� �� �� ����.
  �� �Ŀ� ���� C-1 ������ ���ô� ���� �����Ӱ� �ٴ� �� �ִ�.
  D�� ������ �迭�� �����Ͽ� �� ���� 1, 2, 3, ..., i�� ���ñ��� �湮�� �� �ִ� ����� �÷��̵� �˰��� �ᱣ���� �����Ѵ�.
  ���� �������� ���ϴ� ���� �޾� ��¸� �ϸ� �ȴ�.
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

    // 3���� �迭 D�� ù �ε����� 1, 2, ..., i�� ���ñ��� ���� �� �� ���� ���� �ּ� �Ÿ����� ����
    // ��, D[i][s][e] �� �߰� ������ ��ȣ�� i �������� �����ϸ鼭 s ���� e ���� �����ϴ� �Ÿ��� �ּڰ��̴�.
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
