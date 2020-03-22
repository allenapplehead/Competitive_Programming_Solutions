#include <bits/stdc++.h>
using namespace std;

int N, k;

int dp[1000][120][120];

int f(int cur, int left, int lower) {
    int ways = 0;

    // base cases
    if (N == k) {
        return 1;
    }
    if (left == 1) {
        return 1;
    }
    if (dp[cur][left][lower]) {
        return dp[cur][left][lower];
    }
    for (int i = lower; i < (cur / left) + 1; i++) {
        ways += f(cur - i, left - 1, i);
    }
    dp[cur][left][lower] = ways;
    return ways;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> k;
    cout << f(N, k, 1) << "\n";
    return 0;
}