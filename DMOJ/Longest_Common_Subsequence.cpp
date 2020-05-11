#include<bits/stdc++.h> 
using namespace std;

int dp[1002][1002];
int n1, n2, a[1002], b[1002];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) 
        cin >> a[i];
    for (int j = 0; j < n2; j++) {
        cin >> b[j];
    }
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]); 
            }
            // move right
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            // move down
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[n1][n2] << "\n";
    return 0;
}