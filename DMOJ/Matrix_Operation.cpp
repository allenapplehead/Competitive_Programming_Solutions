#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

long long grid[2005][2005];
long long dp[2005][2005];

long long ans = 0;
int n;

long long solve(int r, int c) {
    // define the base case
    bool valid = false;
    for (int i = 0; i < 4; ++i) {
        if (grid[r + dy[i]][c + dx[i]] > grid[r][c]) {
            valid = true; // there exists another path go to
            if (dp[r + dy[i]][c + dx[i]] == 0) {
                dp[r + dy[i]][c + dx[i]] = solve(r + dy[i], c + dx[i]); 
            }
            dp[r][c] = max(dp[r][c], dp[r + dy[i]][c + dx[i]] + 1);
        }
    }
    if (!valid) return 0;
    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    // set the outer boundaries to be prohibited
    for (int i = 0; i <= n + 1; ++i) {
        grid[0][i] = -1e9;
        grid[n + 1][i] = -1e9;
        grid[i][0] = -1e9;
        grid[i][n + 1] = -1e9;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << '\n';
    return 0;
}