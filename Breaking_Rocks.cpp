#include <bits/stdc++.h>
using namespace std;

int p, r;
int dp[205][105][105];

int solve(int cs, int last, int level) {
    // base case
    if (level == p - 1) {
        // the last rock can be determined by subtraction
        //cout << "DEBUG: " << cs << '\n';
        if (r - cs >= last && 2 * cs + 1 >= r - cs) {
            //cout << cs << " " << last << '\n';
            return 1;
        } else {
            return 0; // repeated cases, needs to be perfectly sorted
        }
    }
    if (cs > r) 
        return 0;
    // not base case
    int ans = 0;
    if (dp[2 * cs + 1][last][level] == 0) {
        for (int i = last; i <= min(2 * cs + 1, r); ++i) {
            // we are going thru all possible numbers for this state
            //cout << "RECUSRING: " << cs + i << " " << i << " " << level + 1 << '\n';
            ans += solve(cs + i, i, level + 1);
        }
        dp[2 * cs + 1][last][level] = ans;
    } else {
        ans = dp[2 * cs + 1][last][level];
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int ROUNDS = 10;
    for (int i = 0; i < ROUNDS; ++i) {
        cin >> p >> r;
        memset(dp, 0, sizeof(dp));
        cout << solve(1, 1, 1) << '\n';
    }
    return 0;
}