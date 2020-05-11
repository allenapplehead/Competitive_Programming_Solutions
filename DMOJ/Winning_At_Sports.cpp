#include <bits/stdc++.h>
using namespace std;

long long dp[2005][2005];
const long long MOD = 1000000007;

int main() {
    int t, c = 0;
    scanf("%d", &t);
    while (t--) {
        long long ans1, ans2;
        c++;
        long long w, l;
        scanf("%lld-%lld", &w, &l);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        // solve for non stressful
        for (int i = 1; i <= l + 1; i++) {
            for (int j = i + 1; j <= w + 1; j++) {
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                ans1 = dp[i][j] % MOD;
            }
        }
        // solve for stressful
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for (int i = 1; i <= l + 1; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                ans2 = dp[i][j] % MOD;
            }
        }
        printf("Case #%d: %lld %lld\n", c, ans1, ans2);
    }
    return 0;
}