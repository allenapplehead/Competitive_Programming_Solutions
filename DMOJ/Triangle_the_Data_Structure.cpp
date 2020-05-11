#include <bits/stdc++.h>
using namespace std;

long long dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int n, K;
    long long ans = 0;
    cin >> n >> K;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> dp[i][j];
            ans += dp[i][j];
        }
    }
    if (K == 1) {
        // sum the whole triangle up
        cout << ans << '\n';
        return 0;
    }
    ans = 0;
    int last = 1;
    for (int i = 2; i < K; i = ceil((long double)i * (3.0/2.0))) {
      for (int j = 0; j < n - i + 1; ++j) {
        for (int k = 0; k <= j; ++k) {
            dp[j][k] = max(dp[j][k], max(dp[j + i - last][k], dp[j + i - last][k + i - last]));
            
        }
      }
      last = i;
    }
    //debug - show the dp
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // cout << last << '\n';
    for (int j = 0; j < n - K + 1; ++j) {
        for (int k = 0; k <= j; ++k) {
            ans += max(dp[j][k], max(dp[j + K - last][k], dp[j + K - last][k + K - last]));
            //cout << ans << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}

