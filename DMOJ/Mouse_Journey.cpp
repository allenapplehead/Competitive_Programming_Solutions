#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
long long dp[30][30];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c;
    cin >> r >> c;
    int k;
    cin >> k;
    int nor, noc;
    for (int i = 0; i < k; i++) {
        cin >> nor >> noc;
        dp[nor][noc] = 1;
    }
    // main routine
    dp[1][1] = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (dp[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[r][c] << '\n';
    return 0;
}