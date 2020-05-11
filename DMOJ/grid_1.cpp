#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
bool grid[1001][1001];
long long dp[1001][1001];
int h, w;
long long ans;

long long f (int row, int col) {
    // base cases
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    if (row == h - 1 && col == w - 1) {
        // we reached our target
        return 1;
    }
    if (!grid[row + 1][col] && !grid[row][col + 1]) {
        // no more possible paths
        return 0;
    }

    int sofar = 0;
    if (grid[row + 1][col]) {
        sofar += f (row + 1, col) % MOD;
    }
    if (grid[row][col + 1]) {
        sofar += f (row, col + 1) % MOD;
    }
    dp[row][col] = sofar;
    return sofar % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char cur;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dp[i][j] = -1;
            cin >> cur;
            if (cur == '.') {
                grid[i][j] = true;
            }
        }
    }
    ans = f (0, 0);
    cout << ans % MOD << "\n";
    return 0;
}