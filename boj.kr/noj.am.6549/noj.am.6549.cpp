#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, h;
    cin >> n;

    while (n != 0) {
        stack<long long> mono;
        vector<long long> stick(n + 1, 0);
        long long m = 0;
        for (long long i = 0; i < n + 1; i++) {
            if (i != n) cin >> stick[i];

            while (!mono.empty() && stick[mono.top()] > stick[i]) {
                long long foo = stick[mono.top()];
                long long len = i;
                mono.pop();
                if (!mono.empty()) len = i - mono.top() - 1;
                long long rect = len * foo;
                m = max(rect, m);
            }
            mono.push(i);

        }

        cout << m << "\n";
        cin >> n;
    }
}