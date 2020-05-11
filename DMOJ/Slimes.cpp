#include <bits/stdc++.h>
using namespace std;

vector<long long> ar(405);
long long dp[405][405];

long long sum(int l, int r) {
    long long ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += ar[i];
    }
    return ans;
}

long long solve(int l, int r) {
    if (l == r) {
        return 0;
    }
    long long ans = 1e18;
    for (int i = l; i < r; ++i) {
        if (dp[l][i] == 1e18) {
            dp[l][i] = solve(l, i);
        }
        if (dp[i + 1][r] == 1e18) {
            dp[i + 1][r] = solve(i + 1, r);
        }
        ans = min(ans, dp[l][i] + dp[i + 1][r] + sum(l, r));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    for (int i = 0; i < 405; ++i) {
        for (int j = 0; j < 405; ++j) {
            dp[i][j] = 1e18;
        }
    }
    cout << solve(0, n - 1) << '\n';
    return 0;
}