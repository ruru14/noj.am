#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tc, k;
    cin >> tc;

    while (tc--) {
        cin >> k;
        vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
        vector<int> sum(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            int foo;
            cin >> foo;
            sum[i] += sum[i - 1] + foo;
        }

        for (int r = 1; r <= k; r++) {
            for (int i = 1; i <= k - r; i++) {
                int j = i + r;
                dp[i][j] = 50000000;
                for (int m = i; m < j; m++) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][k] << "\n";

    }
}