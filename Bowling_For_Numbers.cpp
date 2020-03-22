#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, w;
        cin >> n >> k >> w;
        long long dp[k + 1][n + 30000];
        vector<int> a(n + 1); a[0] = 0;
        memset(dp, 0, sizeof(dp));
        for (int t, i = 0; i < n; ++i) {
            cin >> t;
            a[i + 1] = a[i] + t;
        }
        vector<int> s(n);
        // fill in the array of sums first
        for (int i = n - 1; i > n - w; --i) {
            s[i] = a[n] - a[i];
        }
        for (int i = n - w; i >= 0; --i) {
            s[i] = a[i + w] - a[i];
        }
        // fill right to left from top to bottom
        for (int i = 1; i <= k; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(dp[i][j + 1], s[j] + dp[i - 1][j + w]);
            }
        }
        cout << dp[k][0] << '\n';
    }
    return 0;
}