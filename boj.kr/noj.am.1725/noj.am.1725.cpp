#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, h;
    cin >> n;
    stack<long long> mono;
    vector<int> stick(n + 1, 0);
    long long m = 0;
    for (int i = 0; i < n + 1; i++) {
        if (i != n) cin >> stick[i];

        while (!mono.empty() && stick[mono.top()] > stick[i]) {
            int foo = stick[mono.top()];
            int len = i;
            mono.pop();
            if (!mono.empty()) len = i - mono.top() - 1;
            long long rect = len * foo;
            m = max(rect, m);
        }
        mono.push(i);

    }

    cout << m;
}