#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int m, n, x, y;
        int a = 1, b = 1, answer;
        bool flag = true;
        cin >> m >> n >> x >> y;
        answer = x;
        while (answer <= m * n) {
            if ((answer - x) % m == 0 && (answer - y) % n == 0) {
                flag = false;
                cout << answer << "\n";
                break;
            }
            answer += m;
        }
        if (flag) cout << -1 << "\n";
    }
}