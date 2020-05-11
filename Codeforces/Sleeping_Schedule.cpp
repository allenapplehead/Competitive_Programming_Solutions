#include <bits/stdc++.h>
using namespace std;

// did not really use editorial, my recursive solution works
// THE ERROR: MAKE SURE YOU KNOW CLEARLY WHAT IS HAPPENING AT THE END OF THE RECURSION: WHERE THE BASE CASE IS BEING HIT
// ANOTHER ERROR: MAKE SURE YOU IMPLEMENT DP THE WAY SHOWN BELOW (FOR BOTH BRANCHES) INSTEAD OF THE MAX OF THE TWO OR ELSE IT IS NOT ENOUGH
// CONSIDER ITERATIVE IF YOU WISH, ITS ACTUALLY REALLY ELEGANT

int dp[2005][2005];
int ar[2005];
 
int n, h, l, r;
int solve(int slept, int hours, int early) {
    // base case
    if (slept == n - 1) {
        if ((hours + ar[slept]) % h >= l && (hours + ar[slept]) % h <= r || (hours + ar[slept] - 1) % h >= l && (hours + ar[slept] - 1) % h <= r) {
            return 1;
        } else {
            return 0;
        }
    }
    // keep searching
    if (dp[slept + 1][(hours + ar[slept] - 1) % n] == -1) {
        dp[slept + 1][(hours + ar[slept] - 1) % n] = solve(slept + 1, (hours + ar[slept] - 1), early + 1);
        //cout << "A: " << dp[slept + 1][early + 1] << '\n';
        if ((hours + ar[slept] - 1) % h >= l && (hours + ar[slept] - 1) % h <= r) {
            dp[slept + 1][(hours + ar[slept] - 1) % n]++;
        }
    }

    if (dp[slept + 1][(hours + ar[slept]) % n] == -1) {
        dp[slept + 1][(hours + ar[slept]) % n] = solve(slept + 1, (hours + ar[slept]), early);
        //cout << "B: " << dp[slept + 1][early] << '\n';
        if ((hours + ar[slept]) % h >= l && (hours + ar[slept]) % h <= r) {
            dp[slept + 1][(hours + ar[slept]) % n]++;
        }
    }

    return max(dp[slept + 1][(hours + ar[slept] - 1) % n], dp[slept + 1][(hours + ar[slept]) % n]);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> h >> l >> r;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    cout << solve(0, 0, 0) << '\n';
    return 0;
}