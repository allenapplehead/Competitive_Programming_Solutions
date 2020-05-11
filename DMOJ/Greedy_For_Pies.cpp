// LESSONS LEARNED
// int& and int is the difference between passing and tle nani
// int& a = b;
// means setting a's ADDRESS to b's ADDRESS in memory
// so that means when you change ret you are changing dp

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[3005];
int b[105];
int dp[3005][2][105][105];

int solve (int pos, int take, int l, int r) {
    int& ret = dp[pos][take][l][r];
    if (ret != -1) {
        return ret;
    }
    if (pos == n + 1) {
        // we are at the end of the line
        if (l <= r) {
            // we can still take pies out of the back or the front
            if (take) {
                ret = b[r] + solve(pos, 0, l, r - 1);
                return ret;
            }
            ret = solve(pos, 1, l + 1, r);
            return ret;
        } else {
            return 0;
        }
    }
    if (take) {
        ret = max(solve(pos, 0, l, r), a[pos] + solve(pos + 1, 0, l, r));
        // max command is needed here if we take the pie when we can or we don't take it so we force it back to a similar state
        if (l <= r) {
            // if we instead eat a pie from the reserve pile
            ret = max(ret, b[r] + solve(pos, 0, l, r - 1));
        }
    } else {
        ret = solve(pos + 1, 1, l, r);
        if (l <= r) {
            ret = max(ret, solve(pos, 1, l + 1, r));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i + 1];
    }
    sort(b + 1, b + 1 + m);
    cout << solve(1, 1, 1, m) << '\n';
    return 0;
}